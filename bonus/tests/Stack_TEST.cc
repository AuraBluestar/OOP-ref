#pragma once
#include <iostream>
#include <gtest/gtest.h>
#include "./include/Stack.h"


TEST(MyStackTest, PushTest) {
    MyStack<int> stack;

    stack.push(5);
    ASSERT_EQ(stack.top(), 5);
    ASSERT_EQ(stack.getSize(), 1);

    stack.push(10);
    ASSERT_EQ(stack.top(), 10);
    ASSERT_EQ(stack.getSize(), 2);
}

TEST(MyStackTest, PopTest) {
    MyStack<int> stack;

    stack.push(5);
    stack.push(10);

    stack.pop();
    ASSERT_EQ(stack.top(), 5);
    ASSERT_EQ(stack.getSize(), 1);

    stack.pop();
    ASSERT_TRUE(stack.empty());
    ASSERT_THROW(stack.top(), std::out_of_range);
}


TEST(MyStackTest, TopTest) {
    MyStack<int> stack;

    stack.push(5);
    stack.push(10);

    ASSERT_EQ(stack.top(), 10);
    ASSERT_EQ(stack.getSize(), 2);

    stack.pop();
    ASSERT_EQ(stack.top(), 5);
    ASSERT_EQ(stack.getSize(), 1);
}


TEST(MyStackTest, EmptyTest) {
    MyStack<int> stack;

    ASSERT_TRUE(stack.empty());

    stack.push(5);
    ASSERT_FALSE(stack.empty());

    stack.pop();
    ASSERT_TRUE(stack.empty());
}

TEST(MyStackTest, ExceptionTest) {
    MyStack<int> stack;

    ASSERT_THROW(stack.pop(), std::out_of_range);
    ASSERT_THROW(stack.top(), std::out_of_range);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}