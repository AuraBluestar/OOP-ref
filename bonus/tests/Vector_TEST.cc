#pragma once
#include <iostream>
#include <gtest/gtest.h>
#include "./include/Vector.h"

class MyVectorTest : public ::testing::Test {
  protected:
    MyVector<int> v_int;
    MyVector<double> v_double;

    void SetUp() override {
        v_int = MyVector<int>();       
        v_double = MyVector<double>(); 
    }

    void TearDown() override {}
};

TEST_F(MyVectorTest, PushBackAndAccess) {
    v_int.push_back(10);
    v_int.push_back(20);
    EXPECT_EQ(v_int[0], 10);
    EXPECT_EQ(v_int[1], 20);
}

TEST_F(MyVectorTest, PopBack) {
    v_int.push_back(10);
    v_int.push_back(20);
    v_int.pop_back();
    EXPECT_EQ(v_int.getSize(), 1);
    EXPECT_EQ(v_int[0], 10);
}

TEST_F(MyVectorTest, GetSizeEmpty) {
    EXPECT_EQ(v_int.getSize(), 0);
}

TEST_F(MyVectorTest, GetSizeAfterPushBack) {
    v_double.push_back(3.14);
    EXPECT_EQ(v_double.getSize(), 1);
}

TEST_F(MyVectorTest, CapacityAfterResize) {
    for (int i = 0; i < 10; ++i) {
        v_int.push_back(i);
    }
    EXPECT_GE(v_int.getSize(), 10);
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(v_int[i], i);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
