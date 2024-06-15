#pragma once
#include <iostream>
#include "gtest/gtest.h"
#include "../bonus/include/Set.h"

class MySetTest : public ::testing::Test {
  protected:
    MySet<int> mySet;

    void SetUp() override {
        mySet.insert(3);
        mySet.insert(1);
        mySet.insert(5);
    }

    void TearDown() override {
        mySet.clear();
    }
};

TEST_F(MySetTest, InsertAndSize) {
    EXPECT_EQ(mySet.getSize(), 3);

    mySet.insert(7);
    EXPECT_EQ(mySet.getSize(), 4);
}

TEST_F(MySetTest, EraseAndSize) {
    mySet.erase(1);
    EXPECT_FALSE(mySet.find(1));
    EXPECT_EQ(mySet.getSize(), 2);
}

TEST_F(MySetTest, FindElement) {
    EXPECT_TRUE(mySet.find(3));
    EXPECT_FALSE(mySet.find(2));
}

TEST_F(MySetTest, IndexOperator) {
    EXPECT_EQ(mySet[0], 1);
    EXPECT_EQ(mySet[1], 3);
    EXPECT_THROW(mySet[3], std::out_of_range);
}

TEST_F(MySetTest, ClearSet) {
    mySet.clear();
    EXPECT_EQ(mySet.getSize(), 0);
    EXPECT_FALSE(mySet.find(3));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
