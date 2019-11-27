// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <random>
#include <chrono>
#include <iostream>

#include "unordered_map.h"

#include "gtest/gtest.h"
#include "GTestNoDeath.h"

namespace {

using std::string;

using namespace ::testing_internal;

class HashTableFixture : public ::testing::Test {
protected:
    static const uint MAX_TESTED_SCORE = 20;
    static const uint MAX_OVERALL_SCORE = 25;
    static uint _testScore;

protected:
    static void TearDownTestCase() {
        if (_testScore == MAX_TESTED_SCORE) {
            std::cout << std::endl << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << std::endl;
        } else {
            std::cout << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                      << ")" << std::endl;
        }

        std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                  << " where the remaining points" << std::endl;
        std::cout << "comes from grading related to documentation, algorithms, and other"
                  << std::endl;
        std::cout << "criteria." << std::endl << std::endl;
    }
};

uint HashTableFixture::_testScore = 0;

// Check std::lists equivalence (go ahead, I dare you) by uncommenting
// this line, and commenting out the following line.
// using std::list;
using edu::vcccd::vc::csv15::unordered_map;

TEST_F(HashTableFixture, TestEmptyHashTable) {
    unordered_map<std::string, int> map;
    ASSERT_TRUE(map.empty());
    ASSERT_EQ(0, map.size());
    ASSERT_EQ(0.0, map.load_factor());
    ASSERT_EQ(map.end(), map.find(std::string("string")));
    _testScore += 3;
}

TEST_F(HashTableFixture, TestBasicHashTable) {
    unordered_map<std::string, int> map;
    map["test1"] = 1;
    ASSERT_EQ(1, map.size());
    ASSERT_EQ(1, map["test1"]);
    ASSERT_NE(map.end(), map.find("test1"));
    _testScore += 3;
}

TEST_F(HashTableFixture, TestOneRehash) {
    unordered_map<std::string, int> map;
    map["test1"] = 1;
    map["test2"] = 2;
    ASSERT_EQ(2, map.size());
    ASSERT_EQ(1, map["test1"]);
    ASSERT_EQ(2, map["test2"]);
    ASSERT_NE(map.end(), map.find("test1"));
    ASSERT_NE(map.end(), map.find("test2"));
    _testScore += 3;
}

TEST_F(HashTableFixture, TestMultipleRehash) {
    unordered_map<std::string, int> map;
    map["test1"] = 1;
    map["test2"] = 2;
    ASSERT_EQ(2, map.size());
    ASSERT_EQ(1, map["test1"]);
    ASSERT_EQ(2, map["test2"]);
    ASSERT_EQ(5, map.bucket_count());
    ASSERT_NE(map.end(), map.find("test1"));
    ASSERT_NE(map.end(), map.find("test2"));
    _testScore += 3;

    map["test3"] = 3;
    map["test4"] = 4;
    ASSERT_EQ(4, map.size());
    ASSERT_EQ(3, map["test3"]);
    ASSERT_EQ(4, map["test4"]);
    ASSERT_EQ(11, map.bucket_count());
    ASSERT_NE(map.end(), map.find("test3"));
    ASSERT_NE(map.end(), map.find("test4"));
    _testScore += 4;

    map["test5"] = 5;
    map["test6"] = 6;
    map["test7"] = 7;
    map["test8"] = 8;
    map["test9"] = 9;
    ASSERT_EQ(9, map.size());
    ASSERT_EQ(5, map["test5"]);
    ASSERT_EQ(6, map["test6"]);
    ASSERT_EQ(7, map["test7"]);
    ASSERT_EQ(8, map["test8"]);
    ASSERT_EQ(9, map["test9"]);
    ASSERT_EQ(23, map.bucket_count());
    ASSERT_NE(map.end(), map.find("test5"));
    ASSERT_NE(map.end(), map.find("test6"));
    ASSERT_NE(map.end(), map.find("test7"));
    ASSERT_NE(map.end(), map.find("test8"));
    ASSERT_NE(map.end(), map.find("test9"));
    _testScore += 4;
}

}
