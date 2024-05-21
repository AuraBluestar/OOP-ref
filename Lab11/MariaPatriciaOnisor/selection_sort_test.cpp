//Teodora Chiriac
#include <gtest/gtest.h>
#include <vector>
#include "selection_sort.h"  

TEST(SelectionSortTest, BasicAssertions) {
    std::vector<int> vec = { 4, 3, 2, 1 };
    selectionSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4}));
}

TEST(SelectionSortTest, AlreadySorted) {
    std::vector<int> vec = { 1, 2, 3, 4 };
    selectionSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4}));
}

TEST(SelectionSortTest, ReverseSorted) {
    std::vector<int> vec = { 4, 3, 2, 1 };
    selectionSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4}));
}

TEST(SelectionSortTest, AllSameElements) {
    std::vector<int> vec = { 1, 1, 1, 1 };
    selectionSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{1, 1, 1, 1}));
}

TEST(SelectionSortTest, EmptyVector) {
    std::vector<int> vec = {};
    selectionSort(vec);
    EXPECT_EQ(vec, (std::vector<int>{}));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
