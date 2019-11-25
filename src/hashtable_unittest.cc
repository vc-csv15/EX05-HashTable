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

#include "stack.h"
#include "balanced.h"

#include "gtest/gtest.h"
#include "GTestNoDeath.h"

namespace {

using std::string;

using namespace ::testing_internal;

class StacksFixture : public ::testing::Test {
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

uint StacksFixture::_testScore = 0;

// Check std::lists equivalence (go ahead, I dare you) by uncommenting
// this line, and commenting out the following line.
// using std::list;
using edu::vcccd::vc::csv15::stack;
using edu::vcccd::vc::csv15::balanced_parens;
using edu::vcccd::vc::csv15::balanced_curly;
using edu::vcccd::vc::csv15::balanced_angle;
using edu::vcccd::vc::csv15::balanced_square;

TEST_F(StacksFixture, TestEmptyStack) {
    stack<int> int_stack;
    ASSERT_TRUE(int_stack.empty());
    ASSERT_EQ(0, int_stack.size());
    _testScore += 2;
}

TEST_F(StacksFixture, TestStackPushTop) {
    stack<float> float_stack;
    float_stack.push(1.0);
    ASSERT_FALSE(float_stack.empty());
    ASSERT_EQ(1, float_stack.size());
    ASSERT_EQ(1.0, float_stack.top());
    _testScore += 2;
}

TEST_F(StacksFixture, TestStackPop) {
    stack<float> float_stack;
    float_stack.push(1.0);
    ASSERT_FALSE(float_stack.empty());
    ASSERT_EQ(1, float_stack.size());
    ASSERT_EQ(1.0, float_stack.top());

    float_stack.pop();
    ASSERT_TRUE(float_stack.empty());
    ASSERT_EQ(0, float_stack.size());
    _testScore += 4;
}

TEST_F(StacksFixture, TestStackPopulated) {
    stack<float> float_stack;
    for (int i = 0; i < 10; i++) {
        float_stack.push(1.0 * (i + 1));
    }

    for (int i = 10; i > 0; i--) {
        float_stack.pop();
        ASSERT_FALSE(float_stack.empty() && i != 1);
        ASSERT_EQ(i-1, float_stack.size());
        if (float_stack.size() > 0) ASSERT_EQ(1.0 * (i-1), float_stack.top());
    }

    ASSERT_TRUE(float_stack.empty());
    ASSERT_EQ(0, float_stack.size());
    _testScore += 2;
}

TEST_F(StacksFixture, TestEmptyParens) {
    bool result = balanced_parens("");
    std::cout << result << std::endl;
    ASSERT_TRUE(result);
    _testScore += 2;
}

TEST_F(StacksFixture, TestBalancedAngles) {
    ASSERT_TRUE(balanced_angle("<<>><><<<>><>>"));
    _testScore += 2;
}

TEST_F(StacksFixture, TestUnbalancedCurlys) {
    bool result = balanced_curly("{{}}{}{{}}{}}");
    std::cout << result << std::endl;
    ASSERT_FALSE(result);
    _testScore += 3;
}

TEST_F(StacksFixture, TestUnalancedSquares) {
    ASSERT_FALSE(balanced_square("[[]][][[[][]]"));
    _testScore += 3;
}

}
