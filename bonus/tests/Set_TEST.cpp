#pragma once
#include <iostream>
#include <cassert>
#include "../bonus/include/Set.h"

void testInsert() {
    MySet<int> set;
    set.insert(5);
    set.insert(2);
    set.insert(8);

    assert(set.getSize() == 3);
    assert(set.find(5) == true);
    assert(set.find(2) == true);
    assert(set.find(8) == true);
    assert(set.find(10) == false); // 10 nu ar trebui sa fie in set

    std::cout << "Insert test passed.\n";
}

void testErase() {
    MySet<int> set;
    set.insert(5);
    set.insert(2);
    set.insert(8);
    set.erase(2);

    assert(set.getSize() == 2);
    assert(set.find(2) == false); // 2 nu ar trebui sa fie in set

    std::cout << "Erase test passed.\n";
}

void testFind() {
    MySet<int> set;
    set.insert(5);
    set.insert(2);
    set.insert(8);

    assert(set.find(5) == true);
    assert(set.find(3) == false); // 3 nu ar trebui sa fie in set

    std::cout << "Find test passed.\n";
}

void testSize() {
    MySet<int> set;
    assert(set.getSize() == 0);

    set.insert(5);
    set.insert(2);
    set.insert(8);

    assert(set.getSize() == 3);

    set.erase(2);
    assert(set.getSize() == 2);

    set.clear();
    assert(set.getSize() == 0);

    std::cout << "Size test passed.\n";
}

void testIndexOperator() {
    MySet<int> set;
    set.insert(5);
    set.insert(2);
    set.insert(8);

    assert(set[0] == 2);
    assert(set[1] == 5);
    assert(set[2] == 8);

    bool outOfRange = false;
    try {
        int value = set[3];
    } catch (const std::out_of_range& e) {
        outOfRange = true;
    }
    assert(outOfRange);

    std::cout << "Index operator test passed.\n";
}

int main() {
    testInsert();
    testErase();
    testFind();
    testSize();
    testIndexOperator();

    return 0;
}