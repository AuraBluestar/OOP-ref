#include<gtest/gtest.h>
#include "./include/Deque.h"

TEST(MyDequeTest, PushBackTest) {
    MyDeque<int> deque;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);

    EXPECT_EQ(deque.back(), 3);
    EXPECT_EQ(deque.getSize(), 3);
}

TEST(MyDequeTest, PushFrontTest) {
    MyDeque<int> deque;

    deque.push_front(1);
    deque.push_front(2);
    deque.push_front(3);

    EXPECT_EQ(deque.front(), 3);
    EXPECT_EQ(deque.getSize(), 3);
}

TEST(MyDequeTest, PopBackTest) {
    MyDeque<int> deque;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);

    deque.pop_back();
    EXPECT_EQ(deque.back(), 2);
    EXPECT_EQ(deque.getSize(), 2);

    deque.pop_back();
    EXPECT_EQ(deque.back(), 1);
    EXPECT_EQ(deque.getSize(), 1);
}

TEST(MyDequeTest, PopFrontTest) {
    MyDeque<int> deque;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);

    deque.pop_front();
    EXPECT_EQ(deque.front(), 2);
    EXPECT_EQ(deque.getSize(), 2);

    deque.pop_front();
    EXPECT_EQ(deque.front(), 3);
    EXPECT_EQ(deque.getSize(), 1);
}

TEST(MyDequeTest, FrontBackTest) {
    MyDeque<int> deque;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);

    EXPECT_EQ(deque.front(), 1);
    EXPECT_EQ(deque.back(), 3);

    deque.pop_front();
    EXPECT_EQ(deque.front(), 2);
    EXPECT_EQ(deque.back(), 3);

    deque.pop_back();
    EXPECT_EQ(deque.front(), 2);
    EXPECT_EQ(deque.back(), 2);
}
