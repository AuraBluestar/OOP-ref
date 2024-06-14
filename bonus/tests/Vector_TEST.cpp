#pragma once
#include <iostream>
#include <cassert>
#include "../bonus/include/Vector.h"

void testPushBackAndAccess() {
    MyVector<int> vec;

    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(3);

    assert(vec[0] == 5);
    assert(vec[1] == 10);
    assert(vec[2] == 3);
    assert(vec.getSize() == 3);

    std::cout << "Push back and Access test passed.\n";
}

void testPopBack() {
    MyVector<int> vec;

    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(3);

    vec.pop_back();
    assert(vec.getSize() == 2);
    assert(vec[0] == 5);
    assert(vec[1] == 10);

    vec.pop_back();
    vec.pop_back();
    assert(vec.getSize() == 0);

    std::cout << "Pop back test passed.\n";
}

void testIndexOperator() {
    MyVector<int> vec;

    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(3);

    assert(vec[0] == 5);
    assert(vec[1] == 10);
    assert(vec[2] == 3);

    std::cout << "Index operator test passed.\n";
}

void testSize() {
    MyVector<int> vec;

    assert(vec.getSize() == 0);

    vec.push_back(5);
    vec.push_back(10);

    assert(vec.getSize() == 2);

    vec.pop_back();
    assert(vec.getSize() == 1);

    vec.pop_back();
    assert(vec.getSize() == 0);

    std::cout << "Size test passed.\n";
}

void testResize() {
    MyVector<int> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    assert(vec.getSize() == 10);
    for (int i = 0; i < 10; ++i) {
        assert(vec[i] == i);
    }

    std::cout << "Resize test passed.\n";
}

int main() {
    testPushBackAndAccess();
    testPopBack();
    testIndexOperator();
    testSize();
    testResize();

    return 0;
}