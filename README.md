```bash
❯ g++-11 example3.cpp -I/home/ddk/study/leveldb-learning/leveldb/include -L/home/ddk/study/leveldb-learning/leveldb/build -lleveldb
❯ ./a.out
128690823284544 db_impl.cc:Recover:385 Recovery done
128690823284544 db_impl.cc:RemoveObsoleteFiles:290 Deleted /tmp/testdb-1/MANIFEST-000001
128690823284544 db_impl.cc:Open:1584 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690823284544 db_impl.cc:Put:1532 Put - key: jhqp
128690823284544 db_impl.cc:MakeRoomForWrite:1364 mem_->ApproximateMemoryUsage() = 112
128690823284544 db_impl.cc:Write:1256 Adding 1 records to log. last_sequence = 1
128690823284544 db_impl.cc:Write:1268 Adding 1 records to mem table. last_sequence = 1
128690823284544 db_impl.cc:Write:1302 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690823284544 db_impl.cc:Put:1532 Put - key: rsqs
128690823284544 db_impl.cc:MakeRoomForWrite:1364 mem_->ApproximateMemoryUsage() = 248
128690823284544 db_impl.cc:Write:1256 Adding 1 records to log. last_sequence = 2
128690823284544 db_impl.cc:Write:1268 Adding 1 records to mem table. last_sequence = 2
128690823284544 db_impl.cc:Write:1302 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690823284544 db_impl.cc:Put:1532 Put - key: pqki
128690823284544 db_impl.cc:MakeRoomForWrite:1364 mem_->ApproximateMemoryUsage() = 248
128690823284544 db_impl.cc:Write:1256 Adding 1 records to log. last_sequence = 3
128690823284544 db_impl.cc:Write:1268 Adding 1 records to mem table. last_sequence = 3
128690823284544 db_impl.cc:Write:1302 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690823284544 db_impl.cc:Put:1532 Put - key: gljs
128690823284544 db_impl.cc:MakeRoomForWrite:1364 mem_->ApproximateMemoryUsage() = 248
128690823284544 db_impl.cc:Write:1256 Adding 1 records to log. last_sequence = 4
128690823284544 db_impl.cc:Write:1268 Adding 1 records to mem table. last_sequence = 4
128690823284544 db_impl.cc:Write:1302 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690823284544 db_impl.cc:Put:1532 Put - key: chkb
128690823284544 db_impl.cc:MakeRoomForWrite:1364 mem_->ApproximateMemoryUsage() = 384
128690823284544 db_impl.cc:Write:1256 Adding 1 records to log. last_sequence = 5
128690823284544 db_impl.cc:Write:1268 Adding 1 records to mem table. last_sequence = 5
128690823284544 db_impl.cc:Write:1302 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690823284544 db_impl.cc:Put:1532 Put - key: wzrc
128690823284544 db_impl.cc:MakeRoomForWrite:1364 mem_->ApproximateMemoryUsage() = 384
128690823284544 db_impl.cc:Write:1256 Adding 1 records to log. last_sequence = 6
128690823284544 db_impl.cc:Write:1268 Adding 1 records to mem table. last_sequence = 6
128690823284544 db_impl.cc:Write:1302 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690823284544 db_impl.cc:Put:1532 Put - key: sbhb
128690823284544 db_impl.cc:MakeRoomForWrite:1364 mem_->ApproximateMemoryUsage() = 384
128690823284544 db_impl.cc:Write:1256 Adding 1 records to log. last_sequence = 7
128690823284544 db_impl.cc:Write:1268 Adding 1 records to mem table. last_sequence = 7
128690823284544 db_impl.cc:Write:1302 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690823284544 db_impl.cc:Put:1532 Put - key: hzlr
128690823284544 db_impl.cc:MakeRoomForWrite:1364 mem_->ApproximateMemoryUsage() = 520
128690823284544 db_impl.cc:MakeRoomForWrite:1401 There is no more space in the current 1st mem table. Creating a new log file for the 2nd memtable with log number : 4
128690823284544 db_impl.cc:MakeRoomForWrite:1405 mem_->ApproximateMemoryUsage() = 520
128690823284544 db_impl.cc:MakeRoomForWrite:1409 Created new log file /tmp/testdb-1/000004.log
128690823284544 db_impl.cc:MakeRoomForWrite:1440 Scheduling compaction ...
128690823284544 db_impl.cc:Write:1256 Adding 1 records to log. last_sequence = 8
128690823284544 db_impl.cc:Write:1268 Adding 1 records to mem table. last_sequence = 8
128690823284544 db_impl.cc:Write:1302 Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

Successfully wrote 8 key-value pairs to LevelDB.
128690823284544 db_impl.cc:Get:1145 Get from snapshot : 8
128690823284544 memtable.cc:Get:139 Not found in memtable, key: jhqp
128690823284544 db_impl.cc:Get:1183 Searched in immutable memtable key: jhqp - value:Value_0 status : OK
128690823284544 db_impl.cc:Get:1145 Get from snapshot : 8
128690823284544 memtable.cc:Get:139 Not found in memtable, key: rsqs
128690823284544 db_impl.cc:Get:1183 Searched in immutable memtable key: rsqs - value:Value_1 status : OK
128690823284544 db_impl.cc:Get:1145 Get from snapshot : 8
128690823284544 memtable.cc:Get:139 Not found in memtable, key: pqki
128690816022080 db_impl.cc:BackgroundCompaction:710 Starting Background Compaction
128690816022080 db_impl.cc:BackgroundCompaction:711 Before compaction: Current version status: --- level 0 ---
--- level 1 ---
--- level 2 ---
--- level 3 ---
--- level 4 ---
--- level 5 ---
--- level 6 ---

128690816022080 db_impl.cc:CompactMemTable:555 Compacting mem table
128690823284544 db_impl.cc:Get:1183 Searched in immutable memtable key: pqki - value:Value_2 status : OK
128690823284544 db_impl.cc:Get:1145 Get from snapshot : 8
128690823284544 memtable.cc:Get:139 Not found in memtable, key: gljs
128690823284544 db_impl.cc:Get:1183 Searched in immutable memtable key: gljs - value:Value_3 status : OK
128690823284544 db_impl.cc:Get:1145 Get from snapshot : 8
128690823284544 memtable.cc:Get:139 Not found in memtable, key: chkb
128690823284544 db_impl.cc:Get:1183 Searched in immutable memtable key: chkb - value:Value_4 status : OK
128690823284544 db_impl.cc:Get:1145 Get from snapshot : 8
128690823284544 memtable.cc:Get:139 Not found in memtable, key: wzrc
128690823284544 db_impl.cc:Get:1183 Searched in immutable memtable key: wzrc - value:Value_5 status : OK
128690823284544 db_impl.cc:Get:1145 Get from snapshot : 8
128690823284544 memtable.cc:Get:139 Not found in memtable, key: sbhb
128690823284544 db_impl.cc:Get:1183 Searched in immutable memtable key: sbhb - value:Value_6 status : OK
128690823284544 db_impl.cc:Get:1145 Get from snapshot : 8
128690823284544 db_impl.cc:Get:1183 Searched in memtable key: hzlr - value:Value_7 status : OK
128690816022080 builder.cc:BuildTable:34 Created one NewWritableFile file for SSTable : /tmp/testdb-1/000005.ldb
128690816022080 builder.cc:BuildTable:37 Created table builder SSTable : /tmp/testdb-1/000005.ldb
128690816022080 builder.cc:BuildTable:42 Adding key: chkb to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Add:126 Adding key: chkb to data block
128690816022080 table_builder.cc:Add:130 Current data block estimated size: 30 and r->options.block_siz: 32
128690816022080 builder.cc:BuildTable:42 Adding key: gljs to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Add:126 Adding key: gljs to data block
128690816022080 table_builder.cc:Add:130 Current data block estimated size: 52 and r->options.block_siz: 32
128690816022080 table_builder.cc:Add:134 Flushing block. Current size:  52 vs options.block_size: 32
128690816022080 table_builder.cc:Flush:146 Calling WriteBlock
128690816022080 table_builder.cc:WriteBlock:166 DataBlock contents: 000c0763686b62010500000000000056616c75655f34000c07676c6a73010400000000000056616c75655f330000000001000000
128690816022080 table_builder.cc:WriteRawBlock:216 Block handle offset: 0 | size: 52
128690816022080 table_builder.cc:WriteRawBlock:225 Adding block trailer: 005bbe62a1 to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:WriteRawBlock:231 Current offset is: 57 in the SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 builder.cc:BuildTable:42 Adding key: jhqp to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Add:126 Adding key: jhqp to data block
128690816022080 table_builder.cc:Add:130 Current data block estimated size: 30 and r->options.block_siz: 32
128690816022080 builder.cc:BuildTable:42 Adding key: pqki to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Add:126 Adding key: pqki to data block
128690816022080 table_builder.cc:Add:130 Current data block estimated size: 52 and r->options.block_siz: 32
128690816022080 table_builder.cc:Add:134 Flushing block. Current size:  52 vs options.block_size: 32
128690816022080 table_builder.cc:Flush:146 Calling WriteBlock
128690816022080 table_builder.cc:WriteBlock:166 DataBlock contents: 000c076a687170010100000000000056616c75655f30000c0770716b69010300000000000056616c75655f320000000001000000
128690816022080 table_builder.cc:WriteRawBlock:216 Block handle offset: 57 | size: 52
128690816022080 table_builder.cc:WriteRawBlock:225 Adding block trailer: 004b1a2bf8 to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:WriteRawBlock:231 Current offset is: 114 in the SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 builder.cc:BuildTable:42 Adding key: rsqs to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Add:126 Adding key: rsqs to data block
128690816022080 table_builder.cc:Add:130 Current data block estimated size: 30 and r->options.block_siz: 32
128690816022080 builder.cc:BuildTable:42 Adding key: sbhb to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Add:126 Adding key: sbhb to data block
128690816022080 table_builder.cc:Add:130 Current data block estimated size: 52 and r->options.block_siz: 32
128690816022080 table_builder.cc:Add:134 Flushing block. Current size:  52 vs options.block_size: 32
128690816022080 table_builder.cc:Flush:146 Calling WriteBlock
128690816022080 table_builder.cc:WriteBlock:166 DataBlock contents: 000c0772737173010200000000000056616c75655f31000c0773626862010700000000000056616c75655f360000000001000000
128690816022080 table_builder.cc:WriteRawBlock:216 Block handle offset: 114 | size: 52
128690816022080 table_builder.cc:WriteRawBlock:225 Adding block trailer: 0012484dcd to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:WriteRawBlock:231 Current offset is: 171 in the SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 builder.cc:BuildTable:42 Adding key: wzrc to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Add:126 Adding key: wzrc to data block
128690816022080 table_builder.cc:Add:130 Current data block estimated size: 30 and r->options.block_siz: 32
128690816022080 builder.cc:BuildTable:51 Calling Finish on builder
128690816022080 table_builder.cc:Flush:146 Calling WriteBlock
128690816022080 table_builder.cc:WriteBlock:166 DataBlock contents: 000c07777a7263010600000000000056616c75655f350000000001000000
128690816022080 table_builder.cc:WriteRawBlock:216 Block handle offset: 171 | size: 30
128690816022080 table_builder.cc:WriteRawBlock:225 Adding block trailer: 001011e3e9 to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:WriteRawBlock:231 Current offset is: 206 in the SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Finish:267 Writing meta index block to /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:WriteBlock:166 MetaIndexBlock contents: 0000000001000000
128690816022080 table_builder.cc:WriteRawBlock:216 Block handle offset: 206 | size: 8
128690816022080 table_builder.cc:WriteRawBlock:225 Adding block trailer: 00c0f2a1b0 to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:WriteRawBlock:231 Current offset is: 219 in the SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Finish:281 Writing index block to /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:WriteBlock:166 IndexBlock contents: 0009026801ffffffffffffff00340009027101ffffffffffffff39340009027401ffffffffffffff72340009037801ffffffffffffffab011e000000000e0000001c0000002a00000004000000
128690816022080 table_builder.cc:WriteRawBlock:216 Block handle offset: 219 | size: 77
128690816022080 table_builder.cc:WriteRawBlock:225 Adding block trailer: 00791b7f6d to SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:WriteRawBlock:231 Current offset is: 301 in the SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Finish:287 Appending footer to /tmp/testdb-1/000005.ldb
128690816022080 table_builder.cc:Finish:296 Current offset is: 349 in the SSTable file: /tmp/testdb-1/000005.ldb
128690816022080 builder.cc:BuildTable:57 Done building SSTable : /tmp/testdb-1/000005.ldb
128690816022080 builder.cc:BuildTable:74 Verify that the table is usable by creating a new iterator to /tmp/testdb-1/000005.ldb
128690816022080 format.cc:DecodeFrom:49 
128690816022080 format.cc:DecodeFrom:67 Decoded metaindex handle [offset: 206 size: 8] from ce0108
128690816022080 format.cc:DecodeFrom:79 Decoded index handle [offset: 219 size: 77] from db014d
128690816022080 table.cc:Open:64 Reading index block
128690816022080 table.cc:Open:70 Index block: 0009026801ffffffffffffff00340009027101ffffffffffffff39340009027401ffffffffffffff72340009037801ffffffffffffffab011e000000000e0000001c0000002a00000004000000
128690816022080 table_cache.cc:FindTable:76 Created a new cache entry with key: 5 and file:/tmp/testdb-1/000005.ldb
128690816022080 db_impl.cc:WriteLevel0Table:526 Writing to Level0 files, table: 5 of file size: 349
128690816022080 db_impl.cc:RemoveObsoleteFiles:290 Deleted /tmp/testdb-1/000003.log
```