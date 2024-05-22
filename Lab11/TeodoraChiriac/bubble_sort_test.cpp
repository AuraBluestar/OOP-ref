//Onisor Maria Patricia
#include "bubble_sort.cpp"
#include <gtest/gtest.h>
#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) { 
                std::swap(arr[j], arr[j + 1]); 
            }
        }
    }
}

TEST(BubbleSortTest, BasicAssertions) {
    std::vector<int> vec = { 4, 3, 2, 1 };
    bubbleSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{ 4, 3, 2, 1 }));
}

TEST(BubbleSortTest, AlreadySorted) {
    std::vector<int> vec = { 1, 2, 3, 4 };
    bubbleSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{ 4, 3, 2, 1 }));
}

TEST(BubbleSortTest, ReverseSorted) {
    std::vector<int> vec = { 4, 3, 2, 1 };
    bubbleSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{ 4, 3, 2, 1 }));
}

TEST(BubbleSortTest, AllSameElements) {
    std::vector<int> vec = { 1, 1, 1, 1 };
    bubbleSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{ 1, 1, 1, 1 }));
}

TEST(BubbleSortTest, EmptyVector) {
    std::vector<int> vec = {};
    bubbleSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{}));
}
