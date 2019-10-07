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

#include <list>
#include "list.h"

#include "gtest/gtest.h"
#include "GTestNoDeath.h"

namespace {

using std::string;

using namespace ::testing_internal;

class LinkedListsFixture : public ::testing::Test {
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

uint LinkedListsFixture::_testScore = 0;

// Check std::lists equivalence (go ahead, I dare you) by uncommenting
// this line, and commenting out the following line.
// using std::list;
using edu::vcccd::vc::csv15::list;

TEST_F(LinkedListsFixture, TestPushPopFront) {
    list<int> ints;
    ints.push_front(5);
    ASSERT_EQ(1, ints.size());
    ASSERT_EQ(5, ints.front());
    ints.pop_front();
    ASSERT_EQ(0, ints.size());
    _testScore += 2;
}

TEST_F(LinkedListsFixture, TestPushPopBack) {
    list<std::string> strings;
    strings.push_back("hello");
    ASSERT_EQ(1, strings.size());
    ASSERT_STREQ("hello", strings.back().c_str());
    strings.pop_back();
    ASSERT_EQ(0, strings.size());
    _testScore += 2;
}

TEST_F(LinkedListsFixture, TestPushPopFrontBack) {
    list<char> chars;
    chars.push_back('z');
    chars.push_front('a');
    ASSERT_EQ(2, chars.size());
    ASSERT_EQ('z', chars.back());
    ASSERT_EQ('a', chars.front());
    chars.pop_front();
    ASSERT_EQ(1, chars.size());
    chars.pop_back();
    ASSERT_EQ(0, chars.size());

    _testScore += 2;
}

TEST_F(LinkedListsFixture, TestInsertInterior) {
    list<int> ints(2, 10);
    ints.insert(++ints.begin(), 3);
    auto i = ints.begin();
    ASSERT_EQ(3, ints.size());
    ASSERT_EQ(10, *(i++));
    ASSERT_EQ(3, *(i++));
    ASSERT_EQ(10, *i);
    _testScore += 2;
}

TEST_F(LinkedListsFixture, TestDeleteInterior) {
    list<int> ints(3, 12);
    ints.erase(++ints.begin());
    auto i = ints.begin();
    ASSERT_EQ(2, ints.size());
    ASSERT_EQ(12, ints.front());
    ASSERT_EQ(12, ints.back());

    _testScore += 2;
}

TEST_F(LinkedListsFixture, TestEraseInteriorIterator) {
    list<int> ints;
    for (int i = 0; i < 10; i++) {
        ints.push_back(i);
    }

    auto i = ++ints.begin();
    ints.erase(++ints.begin(), ++(++(++(++(++(++(++(++(i)))))))));
    ASSERT_EQ(2, ints.size());
    ASSERT_EQ(0, ints.front());
    ASSERT_EQ(9, ints.back());
    _testScore += 2;
}

TEST_F(LinkedListsFixture, TestClear) {
    list<const char*> strings(10, "hello");
    ASSERT_EQ("hello", strings.front());
    ASSERT_EQ("hello", strings.back());
    ASSERT_EQ(10, strings.size());
    strings.clear();
    ASSERT_EQ(0, strings.size());
    _testScore += 2;
}

TEST_F(LinkedListsFixture, TestInsertIterator) {
    list<int64_t> ints;
    ints.push_back(10);
    auto insert = ints.insert(++ints.begin(), 11);
    ASSERT_EQ(2, ints.size());
    ASSERT_EQ(11, ints.back());
    ASSERT_EQ(++ints.begin(), insert);
    _testScore += 1;

    insert = ints.insert(ints.begin(), 9);
    ASSERT_EQ(3, ints.size());
    ASSERT_EQ(9, ints.front());
    ASSERT_EQ(ints.begin(), insert);
    _testScore += 1;
}

TEST_F(LinkedListsFixture, TestEraseIterator) {
    list<int64_t> ints;
    ints.push_back(10);
    ints.push_back(11);
    ints.push_back(12);
    ints.push_back(13);

    auto it = ints.begin();
    auto after = ints.erase(++ints.begin(), ++(++(++(it))));
    ASSERT_EQ(2, ints.size());
    ASSERT_EQ(10, ints.front());
    ASSERT_EQ(13, ints.back());
    ASSERT_EQ(++ints.begin(), after);
    _testScore += 1;

    after = ints.erase(ints.begin());
    ASSERT_EQ(1, ints.size());
    ASSERT_EQ(13, ints.back());
    ASSERT_EQ(ints.begin(), after);
    _testScore += 1;
}

TEST_F(LinkedListsFixture, TestLarge) {
    list<int64_t > ints(100000, INT64_MAX);
    ASSERT_EQ(100000, ints.size());
    ASSERT_EQ(INT64_MAX, ints.front());
    ASSERT_EQ(INT64_MAX, ints.back());
    ints.clear();
    ints.clear();
    ASSERT_EQ(0, ints.size());
    _testScore += 2;
}
}
