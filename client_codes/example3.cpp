/**
 * Write N keys and read them as well
*/
#include <chrono>
#include <iostream>
#include <leveldb/db.h>
#include <random>
#include <string>
#include <thread>
#include <utility>
#include <vector>

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

const int num_keys_to_add = 8;

int main() {
    // Open LevelDB database
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    options.write_buffer_size = 512;
    options.block_size = 32;
    options.compression = leveldb::CompressionType::kNoCompression;

    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb-1", &db);

    if (!status.ok()) {
        std::cerr << "Unable to open database: " << status.ToString() << std::endl;

        return 1;
    }

    std::vector<std::pair<std::string,std::string>> added_key_values;

    for (int i = 0; i < num_keys_to_add; ++i) {
        std::string key = generateRandomKey();
        std::string value = "Value_" + std::to_string(i);

        // Insert key-value pair into the database
        status = db->Put(leveldb::WriteOptions(), key, value);
        if (!status.ok()) {
          std::cerr << "Error while writing to database: " << status.ToString()
                    << std::endl;
          delete db;
          return 1;
        }
        added_key_values.emplace_back(key,value);
    }

    std::cout << "Successfully wrote " << num_keys_to_add
              << " key-value pairs to LevelDB." << std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(1));

    for (const auto& [key , val] : added_key_values) {
        std::string temp_val;
        // Get key-value pair from the database
        status = db->Get(leveldb::ReadOptions(), key, &temp_val);
        if (!status.ok()) {
          std::cerr << "Error while writing to database: " << status.ToString()
                    << std::endl;
          delete db;
          return 1;
        }
        assert(temp_val == val);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    delete db;
    return 0;
}
