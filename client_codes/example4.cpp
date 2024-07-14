/**
 * Write N keys and read them as well
 */
#include <chrono>
#include <deque>
#include <iostream>
#include <leveldb/db.h>
#include <random>
#include <string>
#include <thread>
#include <utility>
#include <vector>

std::string getRandomString() {
  static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";

  static std::default_random_engine generator(
      static_cast<unsigned int>(std::time(0)));
  static std::uniform_int_distribution<int> distribution(0,
                                                         sizeof(alphanum) - 2);

  std::string randomString;
  for (int i = 0; i < 4; ++i) {
    randomString += alphanum[distribution(generator)];
  }
  return randomString;
}

std::string getRandomStringWithDuplicates() {
  static std::deque<std::string> previousStrings;
  // Maximum number of previous strings to store
  static const int bufferSize = 10;
  static std::default_random_engine generator(
      static_cast<unsigned int>(std::time(0)));
  // 0 to 4, so 1 out of 5 chance for 0
  static std::uniform_int_distribution<int> distribution(0, 4);
  static std::uniform_int_distribution<int> previousDist;

  if (!previousStrings.empty() && distribution(generator) == 0) {
    previousDist =
        std::uniform_int_distribution<int>(0, previousStrings.size() - 1);
    return previousStrings[previousDist(generator)];
  } else {
    std::string newString = getRandomString();
    if (previousStrings.size() == bufferSize) {
      previousStrings.pop_front();
    }
    previousStrings.push_back(newString);
    return newString;
  }
}

const int num_keys_to_add = 34;

int main() {
  // Open LevelDB database
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  options.write_buffer_size = 512;
  options.block_size = 32;
  options.max_file_size = 512;
  options.level01_max_bytes = 1536;  // 1.5 KB or ~3 files of size max_file_size
  options.compression = leveldb::CompressionType::kNoCompression;

  leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb-1", &db);

  if (!status.ok()) {
    std::cerr << "Unable to open database: " << status.ToString() << std::endl;

    return 1;
  }

  std::vector<std::pair<std::string, std::string>> added_key_values;

  for (int i = 0; i < num_keys_to_add; ++i) {
    std::string key = getRandomStringWithDuplicates();
    std::string value = "Value_" + std::to_string(i);

    // Insert key-value pair into the database
    status = db->Put(leveldb::WriteOptions(), key, value);
    if (!status.ok()) {
      std::cerr << "Error while writing to database: " << status.ToString()
                << std::endl;
      delete db;
      return 1;
    }
    added_key_values.emplace_back(key, value);
  }

  std::cout << "Successfully wrote " << num_keys_to_add
            << " key-value pairs to LevelDB." << std::endl;

#ifdef READ
  for (const auto& [key, val] : added_key_values) {
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
#endif

  std::this_thread::sleep_for(std::chrono::seconds(1));
  delete db;
  return 0;
}
