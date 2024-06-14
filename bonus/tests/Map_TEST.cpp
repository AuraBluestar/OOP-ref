#include <gtest/gtest.h>
#include "../bonus/include/Map.h" 

TEST(MyMapTest, InsertTest) {
    MyMap<int, std::string> map;
    map.insert(1, "one");

    ASSERT_EQ(map.getSize(), 1);

    std::string value;
    bool found = map.find(1, value);
    ASSERT_TRUE(found);
    ASSERT_EQ(value, "one");
}

TEST(MyMapTest, UpdateTest) {
    MyMap<int, std::string> map;
    map.insert(1, "one");
    map.insert(2, "two");

    map.insert(1, "updated");

    ASSERT_EQ(map.getSize(), 2);

    std::string value;
    bool found = map.find(1, value);
    ASSERT_TRUE(found);
    ASSERT_EQ(value, "updated");
}

TEST(MyMapTest, FindTest) {
    MyMap<int, std::string> map;
    map.insert(1, "one");

    std::string value;
    bool found = map.find(1, value);

    ASSERT_TRUE(found);
    ASSERT_EQ(value, "one");
}

TEST(MyMapTest, EraseTest) {
    MyMap<int, std::string> map;
    map.insert(1, "one");
    map.insert(2, "two");

    map.erase(1);

    ASSERT_EQ(map.getSize(), 1);

    std::string value;
    bool found = map.find(1, value);
    ASSERT_FALSE(found); // Cheia 1 nu mai este în mapă
}

TEST(MyMapTest, SizeTest) {
    MyMap<int, std::string> map;
    ASSERT_EQ(map.getSize(), 0);

    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    ASSERT_EQ(map.getSize(), 3);

    map.erase(2);

    ASSERT_EQ(map.getSize(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
