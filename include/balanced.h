//
// Created by aknight on 11/10/19.
//

#ifndef EX04_STACKS_BALANCED_H
#define EX04_STACKS_BALANCED_H

#include <string>
#include "stack.h"

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    template <char Open, char Close>
    struct Balancer {
        bool operator ()(const std::string &code) {
            // Put your code below
        }
    };

    extern Balancer<'(', ')'> balanced_parens;
    extern Balancer<'{', '}'> balanced_curly;
    extern Balancer<'[', ']'> balanced_square;
    extern Balancer<'<', '>'> balanced_angle;
}}}}

#endif //EX04_STACKS_BALANCED_H
