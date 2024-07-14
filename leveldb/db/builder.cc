// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "db/builder.h"

#include "db/dbformat.h"
#include "db/filename.h"
#include "db/table_cache.h"
#include "db/version_edit.h"
#include <iostream>
#include <thread>

#include "leveldb/db.h"
#include "leveldb/env.h"
#include "leveldb/iterator.h"

namespace leveldb {

Status BuildTable(const std::string& dbname, Env* env, const Options& options,
                  TableCache* table_cache, Iterator* iter, FileMetaData* meta) {
  Status s;
  meta->file_size = 0;
  iter->SeekToFirst();

  std::string fname = TableFileName(dbname, meta->number);
  meta->file_name = fname;
  if (iter->Valid()) {
    WritableFile* file;
    s = env->NewWritableFile(fname, &file);
    if (!s.ok()) {
      Log(options.info_log, "PQR");
      return s;
    }
    MYPRINT << "Created one NewWritableFile file for SSTable : " << fname
            << std::endl;
    TableBuilder* builder = new TableBuilder(options, file);
    MYPRINT << "Created table builder SSTable : " << fname << std::endl;
    meta->smallest.DecodeFrom(iter->key());
    Slice key;
    for (; iter->Valid(); iter->Next()) {
      key = iter->key();
      MYPRINT << "Adding key: " << EscapeString(key)
              << " to SSTable file: " << fname << std::endl;
      builder->Add(key, iter->value());
    }
    if (!key.empty()) {
      meta->largest.DecodeFrom(key);
    }

    // Finish and check for builder errors
    MYPRINT << "Calling Finish on builder" << std::endl;
    s = builder->Finish();
    Log(options.info_log, "Builder error-1 : %s", s.ToString().c_str());

    if (s.ok()) {
      meta->file_size = builder->FileSize();
      MYPRINT << "Done building SSTable : " << fname << std::endl;
      assert(meta->file_size > 0);
    }
    delete builder;

    // Finish and check for file errors
    if (s.ok()) {
      s = file->Sync();
    }
    if (s.ok()) {
      s = file->Close();
    }
    delete file;
    file = nullptr;

    if (s.ok()) {
      // Verify that the table is usable
      MYPRINT
          << "Verify that the table is usable by creating a new iterator to "
          << fname << std::endl;
      Iterator* it = table_cache->NewIterator(ReadOptions(), meta->number,
                                              meta->file_size);
      s = it->status();
      Log(options.info_log, "Builder error-2 : %s", s.ToString().c_str());
      delete it;
    }
  }

  // Check for input iterator errors
  if (!iter->status().ok()) {
    s = iter->status();
  }

  if (s.ok() && meta->file_size > 0) {
    // Keep it
  } else {
    env->RemoveFile(fname);
  }
  return s;
}

}  // namespace leveldb
