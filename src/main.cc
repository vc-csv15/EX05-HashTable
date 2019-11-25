//
// Created by aknight on 10/7/19.
//

#include <string>
#include <iostream>

#include "unordered_map.h"

using edu::vcccd::vc::csv15::unordered_map;

template <typename Key, typename Val>
constexpr size_t unordered_map<Key, Val>::_BUCKET_SIZES[];

int main(int argc, char *argv[]) {
    unordered_map<std::string, int> map;
    map["other"] = 456;
    map["test"] = 123;
    map["one more"] = 908;
    map["last one"] = 1234;
    std::cout << map["test"] << std::endl;
    std::cout << map["other"] << std::endl;
    std::cout << map["one more"] << std::endl;
    std::cout << map["last one"] << std::endl;
    std::cout << "size: " << map.size() << std::endl;
    std::cout << "bucket count: " << map.bucket_count() << std::endl;
    std::cout << "load factor: " << map.load_factor() << std::endl;

    return EXIT_SUCCESS;
}