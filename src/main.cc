//
// Created by aknight on 10/7/19.
//

#include <string>
#include <iostream>

#include "unordered_map.h"

using edu::vcccd::vc::csv15::unordered_map;
using namespace std;
template <typename Key, typename Val>
constexpr size_t unordered_map<Key, Val>::_BUCKET_SIZES[];

int main(int argc, char *argv[]) {
    unordered_map<std::string, int> map;
    map["other"] = 456;
    map["test"] = 123;
    map["one more"] = 908;
    map["last one"] = 1234;
    map["adsf"] = 123;
    map["dasklfjkdaslf"] = 123423;
    map["this will berak "] = 42069;
    map["will this break it"] = 32423234;
    map["can i do it this time"] = 12361262;
    map["will this one break it hopefully"] = 123123;
    map["asehktldsjakfl"] = 1234;
    map["asehktldsadsfsadfjakfl"] = 1234;
    map["asehktldsjakflasdfasdfsadfsadf"] = 1234;
    map["asehktldsjasdafasdfsadfsdafsdafsdafkfl"] = 1234;
    map["aseadsfhsdafktldsjasdfakfl"] = 1234;
    cout << "last debug before the info " << endl;
    std::cout << map["test"] << std::endl;
    std::cout << map["other"] << std::endl;
    std::cout << map["one more"] << std::endl;
    std::cout << map["last one"] << std::endl;
    std::cout << "size: " << map.size() << std::endl;
    std::cout << "bucket count: " << map.bucket_count() << std::endl;
    std::cout << "load factor: " << map.load_factor() << std::endl;

    return EXIT_SUCCESS;
}