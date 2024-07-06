/**
 * Reads 2 keys from leveldb
*/
#include <iostream>
#include <string>
#include <leveldb/db.h>

int main() {
    // Open LevelDB database
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    options.write_buffer_size = 512;
    options.block_size = 512;
    options.compression = leveldb::CompressionType::kNoCompression;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb-8", &db);
    if (!status.ok()) {
        std::cerr << "Unable to open database: " << status.ToString() << std::endl;
        return 1;
    }

    std::string value;
    status = db->Get(leveldb::ReadOptions(), "abcd", &value);
    if (!status.ok()) {
        std::cerr << "Key does not exits: " << status.ToString() << std::endl;
    }else {
        std::cout << "Value for key: abcd is: " << value << std::endl;
    }

    status = db->Get(leveldb::ReadOptions(), "bifd", &value);
    if (!status.ok()) {
        std::cerr << "Key does not exits: " << status.ToString() << std::endl;
    }else {
        std::cout << "Value for key: bifd is: " << value << std::endl;
    }

    // Close the database
    delete db;

    return 0;
}
