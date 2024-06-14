#pragma once
#include <iostream>
#include <cassert>
#include "../bonus/include/Stack.h"

void testPushAndTop() {
    MyStack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(3);

    assert(stack.top() == 3);
    assert(stack.getSize() == 3);

    stack.pop();
    assert(stack.top() == 10);
    assert(stack.getSize() == 2);

    std::cout << "Push and Top test passed.\n";
}

void testPop() {
    MyStack<int> stack;

    stack.push(5);
    stack.push(10);

    stack.pop();
    assert(stack.top() == 5);
    assert(stack.getSize() == 1);

    stack.pop();
    assert(stack.empty());

    bool emptyException = false;
    try {
        stack.pop();
    } catch (const std::out_of_range& e) {
        emptyException = true;
    }
    assert(emptyException);

    std::cout << "Pop test passed.\n";
}

void testEmpty() {
    MyStack<int> stack;

    assert(stack.empty());

    stack.push(5);
    assert(!stack.empty());

    stack.pop();
    assert(stack.empty());

    std::cout << "Empty test passed.\n";
}

void testSize() {
    MyStack<int> stack;

    assert(stack.getSize() == 0);

    stack.push(5);
    stack.push(10);

    assert(stack.getSize() == 2);

    stack.pop();
    assert(stack.getSize() == 1);

    stack.push(3);
    assert(stack.getSize() == 2);

    std::cout << "Size test passed.\n";
}

void testExceptions() {
    MyStack<int> stack;

    bool emptyException = false;
    try {
        stack.top();
    } catch (const std::out_of_range& e) {
        emptyException = true;
    }
    assert(emptyException);
    emptyException = false;
    try {
        stack.pop(); // popping from empty stack
    } catch (const std::out_of_range& e) {
        emptyException = true;
    }
    assert(emptyException);

    std::cout << "Exception test passed.\n";
}

int main() {
    testPushAndTop();
    testPop();
    testEmpty();
    testSize();
    testExceptions();

    return 0;
}