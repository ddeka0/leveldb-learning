/**
 * Adds 20 random keys to leveldb
*/
#include <iostream>
#include <string>
#include <random>
#include <leveldb/db.h>

// Function to generate random lowercase English letters
char randomLowercaseLetter() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('a', 'z');
    return static_cast<char>(dis(gen));
}

// Function to generate a random key of size 4 letters
std::string generateRandomKey() {
    std::string key;
    for (int i = 0; i < 4; ++i) {
        key += randomLowercaseLetter();
    }
    return key;
}

int main() {
    // Open LevelDB database
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    options.write_buffer_size = 512;
    options.block_size = 512;
    options.compression = leveldb::CompressionType::kNoCompression;
    options.reuse_logs = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb-1", &db);
    if (!status.ok()) {
        std::cerr << "Unable to open database: " << status.ToString() << std::endl;
        return 1;
    }

    int num_keys = 2;
    for (int i = 0; i < num_keys; ++i) {
        std::string key = generateRandomKey();
        std::string value = "Value_" + std::to_string(i);

        // Insert key-value pair into the database
        status = db->Put(leveldb::WriteOptions(), key, value);
        if (!status.ok()) {
            std::cerr << "Error while writing to database: " << status.ToString() << std::endl;
            delete db;
            return 1;
        }
    }

    // Close the database
    delete db;

    std::cout << "Successfully wrote "<< num_keys <<" key-value pairs to LevelDB." << std::endl;

    return 0;
}
