//
// Created by aknight on 11/10/19.
//

#ifndef EX04_STACKS_STACK_H
#define EX04_STACKS_STACK_H

#include "list.h"

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
    template <typename Ty>
    class stack {
        list<Ty> _stack;

    public:
        stack(): _stack() {}
        stack(const stack& x): _stack(x._stack) {}
        stack(stack &&x): _stack(x._stack) {}

    public:
        // Fill in your code below
        bool empty() const {  }
        size_t size() const {  }
        const Ty &top() const {  }
        void push(const Ty &val) {  }
        void pop() {  }
    };
}}}}

#endif //EX04_STACKS_STACK_H
