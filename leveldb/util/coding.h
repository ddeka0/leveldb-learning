// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.
//
// Endian-neutral encoding:
// * Fixed-length numbers are encoded with least-significant byte first
// * In addition we support variable length "varint" encoding
// * Strings are encoded prefixed by their length in varint format

#ifndef STORAGE_LEVELDB_UTIL_CODING_H_
#define STORAGE_LEVELDB_UTIL_CODING_H_

#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>

#include "leveldb/slice.h"

#include "port/port.h"

class ThreadSafeLogger {
 public:
  static ThreadSafeLogger& getInstance() {
    static ThreadSafeLogger instance;
    return instance;
  }

  template <typename T>
  ThreadSafeLogger& operator<<(const T& message) {
    std::lock_guard<std::mutex> guard(mutex_);
    std::ostringstream& buffer = getThreadBuffer();
    buffer << message;
    return *this;
  }

  ThreadSafeLogger& operator<<(std::ostream& (*manipulator)(std::ostream&)) {
    std::lock_guard<std::mutex> guard(mutex_);
    std::ostringstream& buffer = getThreadBuffer();
    buffer << manipulator;
    if (manipulator ==
        static_cast<std::ostream& (*)(std::ostream&)>(std::endl)) {
      std::cout << buffer.str();  // Output the buffered message
      buffer.str("");             // Clear the buffer
      buffer.clear();             // Reset the state of the buffer
      std::cout.flush();          // Flush the output stream
    }
    return *this;
  }

 private:
  ThreadSafeLogger() = default;
  ~ThreadSafeLogger() = default;

  ThreadSafeLogger(const ThreadSafeLogger&) = delete;
  ThreadSafeLogger& operator=(const ThreadSafeLogger&) = delete;

  std::mutex mutex_;
  std::unordered_map<std::thread::id, std::ostringstream> threadBuffers_;

  std::ostringstream& getThreadBuffer() {
    auto tid = std::this_thread::get_id();
    return threadBuffers_[tid];
  }
};

// class ThreadSafeLogger {
//  public:
//   static ThreadSafeLogger& getInstance() {
//     static ThreadSafeLogger instance;
//     return instance;
//   }

//   template <typename T>
//   ThreadSafeLogger& operator<<(const T& message) {
//     std::lock_guard<std::mutex> guard(mutex_);
//     buffer_ << message;
//     return *this;
//   }

//   ThreadSafeLogger& operator<<(std::ostream& (*endl)(std::ostream&)) {
//     std::lock_guard<std::mutex> guard(mutex_);
//     std::cout << buffer_.str();
//     buffer_.str("");
//     buffer_.clear();
//     std::cout << endl;  // Output newline and flush
//     return *this;
//   }

//  private:
//   ThreadSafeLogger() = default;
//   ~ThreadSafeLogger() = default;

//   ThreadSafeLogger(const ThreadSafeLogger&) = delete;
//   ThreadSafeLogger& operator=(const ThreadSafeLogger&) = delete;

//   std::mutex mutex_;
//   std::ostringstream buffer_;
// };

// Function to extract file name from path
std::string ExtractFileName(const std::string& filePath);
std::string GetCurrentDateTime();

#ifndef MYPRINT
#define MYPRINT                                                              \
  ThreadSafeLogger::getInstance()                                            \
      << GetCurrentDateTime() << " " << std::this_thread::get_id() << " "    \
      << ExtractFileName(__FILE__) << ":" << __FUNCTION__ << ":" << __LINE__ \
      << " "
#endif

namespace leveldb {

std::string ByteBufferToString(const std::string& buffer);

// Standard Put... routines append to a string
void PutFixed32(std::string* dst, uint32_t value);
void PutFixed64(std::string* dst, uint64_t value);
void PutVarint32(std::string* dst, uint32_t value);
void PutVarint64(std::string* dst, uint64_t value);
void PutLengthPrefixedSlice(std::string* dst, const Slice& value);

// Standard Get... routines parse a value from the beginning of a Slice
// and advance the slice past the parsed value.
bool GetVarint32(Slice* input, uint32_t* value);
bool GetVarint64(Slice* input, uint64_t* value);
bool GetLengthPrefixedSlice(Slice* input, Slice* result);

// Pointer-based variants of GetVarint...  These either store a value
// in *v and return a pointer just past the parsed value, or return
// nullptr on error.  These routines only look at bytes in the range
// [p..limit-1]
const char* GetVarint32Ptr(const char* p, const char* limit, uint32_t* v);
const char* GetVarint64Ptr(const char* p, const char* limit, uint64_t* v);

// Returns the length of the varint32 or varint64 encoding of "v"
int VarintLength(uint64_t v);

// Lower-level versions of Put... that write directly into a character buffer
// and return a pointer just past the last byte written.
// REQUIRES: dst has enough space for the value being written
char* EncodeVarint32(char* dst, uint32_t value);
char* EncodeVarint64(char* dst, uint64_t value);

// Lower-level versions of Put... that write directly into a character buffer
// REQUIRES: dst has enough space for the value being written

inline void EncodeFixed32(char* dst, uint32_t value) {
  uint8_t* const buffer = reinterpret_cast<uint8_t*>(dst);

  // Recent clang and gcc optimize this to a single mov / str instruction.
  buffer[0] = static_cast<uint8_t>(value);
  buffer[1] = static_cast<uint8_t>(value >> 8);
  buffer[2] = static_cast<uint8_t>(value >> 16);
  buffer[3] = static_cast<uint8_t>(value >> 24);
}

inline void EncodeFixed64(char* dst, uint64_t value) {
  uint8_t* const buffer = reinterpret_cast<uint8_t*>(dst);

  // Recent clang and gcc optimize this to a single mov / str instruction.
  buffer[0] = static_cast<uint8_t>(value);
  buffer[1] = static_cast<uint8_t>(value >> 8);
  buffer[2] = static_cast<uint8_t>(value >> 16);
  buffer[3] = static_cast<uint8_t>(value >> 24);
  buffer[4] = static_cast<uint8_t>(value >> 32);
  buffer[5] = static_cast<uint8_t>(value >> 40);
  buffer[6] = static_cast<uint8_t>(value >> 48);
  buffer[7] = static_cast<uint8_t>(value >> 56);
}

// Lower-level versions of Get... that read directly from a character buffer
// without any bounds checking.

inline uint32_t DecodeFixed32(const char* ptr) {
  const uint8_t* const buffer = reinterpret_cast<const uint8_t*>(ptr);

  // Recent clang and gcc optimize this to a single mov / ldr instruction.
  return (static_cast<uint32_t>(buffer[0])) |
         (static_cast<uint32_t>(buffer[1]) << 8) |
         (static_cast<uint32_t>(buffer[2]) << 16) |
         (static_cast<uint32_t>(buffer[3]) << 24);
}

inline uint64_t DecodeFixed64(const char* ptr) {
  const uint8_t* const buffer = reinterpret_cast<const uint8_t*>(ptr);

  // Recent clang and gcc optimize this to a single mov / ldr instruction.
  return (static_cast<uint64_t>(buffer[0])) |
         (static_cast<uint64_t>(buffer[1]) << 8) |
         (static_cast<uint64_t>(buffer[2]) << 16) |
         (static_cast<uint64_t>(buffer[3]) << 24) |
         (static_cast<uint64_t>(buffer[4]) << 32) |
         (static_cast<uint64_t>(buffer[5]) << 40) |
         (static_cast<uint64_t>(buffer[6]) << 48) |
         (static_cast<uint64_t>(buffer[7]) << 56);
}

// Internal routine for use by fallback path of GetVarint32Ptr
const char* GetVarint32PtrFallback(const char* p, const char* limit,
                                   uint32_t* value);
inline const char* GetVarint32Ptr(const char* p, const char* limit,
                                  uint32_t* value) {
  if (p < limit) {
    uint32_t result = *(reinterpret_cast<const uint8_t*>(p));
    if ((result & 128) == 0) {
      *value = result;
      return p + 1;
    }
  }
  return GetVarint32PtrFallback(p, limit, value);
}

}  // namespace leveldb

#endif  // STORAGE_LEVELDB_UTIL_CODING_H_
