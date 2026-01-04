#include <gtest/gtest.h>
#include "Array_func/array_func.h"
#include "LinkedList/LinkedList.h"
#include "Math_func/Math_func.h"

TEST(GenFTest, NormalCase) {
    std::vector<long long> result = genF(5);
    std::vector<long long> expected = {1, 2, 6, 24, 120};
    EXPECT_EQ(result, expected);
}

TEST(GenFTest, ZeroCase) {
    std::vector<long long> result = genF(0);
    EXPECT_TRUE(result.empty());
}

TEST(RemoveDupTest, BasicCase) {
    std::vector<int> input = {1, 2, 2, 3, 3, 3};
    std::vector<int> result = removeDup(input);
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(result, expected);
}

TEST(RemoveDupTest, EmptyCase) {
    std::vector<int> input = {};
    std::vector<int> result = removeDup(input);
    EXPECT_TRUE(result.empty());
}

TEST(ReverseRecTest, NormalList) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    LinkedList list;
    list.createList(input);
    
    list.reverseRec();
    
    std::vector<int> after = list.toVector();
    std::vector<int> expectedAfter = {5, 4, 3, 2, 1};
    EXPECT_EQ(after, expectedAfter);
}

TEST(ReverseRecTest, SingleElement) {
    std::vector<int> input = {42};
    LinkedList list;
    list.createList(input);
    
    std::vector<int> before = list.toVector();
    EXPECT_EQ(before.size(), 1);
    EXPECT_EQ(before[0], 42);
    
    list.reverseRec();
    
    std::vector<int> after = list.toVector();
    EXPECT_EQ(after.size(), 1);
    EXPECT_EQ(after[0], 42);
}

TEST(ReverseRecTest, EmptyList) {
    std::vector<int> input = {};
    LinkedList list;
    list.createList(input);
    
    std::vector<int> before = list.toVector();
    EXPECT_TRUE(before.empty());

    list.reverseRec();
    
    std::vector<int> after = list.toVector();
    EXPECT_TRUE(after.empty());
}

TEST(ReverseRecTest, TwoElements) {
    std::vector<int> input = {1, 2};
    LinkedList list;
    list.createList(input);
    
    list.reverseRec();
    
    std::vector<int> result = list.toVector();
    std::vector<int> expected = {2, 1};
    EXPECT_EQ(result, expected);
}

TEST(ReverseRecTest, DoubleReverse) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    LinkedList list;
    list.createList(input);
    
    std::vector<int> original = list.toVector();
    
    list.reverseRec();
    list.reverseRec();

    std::vector<int> afterDoubleReverse = list.toVector();
    EXPECT_EQ(original, afterDoubleReverse);
}

TEST(LinkedListTest, CreateListMultipleTimes) {
    LinkedList list;
    
    list.createList({1, 2, 3});
    std::vector<int> first = list.toVector();
    EXPECT_EQ(first, std::vector<int>({1, 2, 3}));
    
    list.createList({4, 5});
    std::vector<int> second = list.toVector();
    EXPECT_EQ(second, std::vector<int>({4, 5}));

    list.createList({});
    std::vector<int> third = list.toVector();
    EXPECT_TRUE(third.empty());
}

TEST(LinkedListTest, DeleteLWorks) {
    LinkedList list;
    list.createList({1, 2, 3, 4, 5});

    list.deleteL();
    
    std::vector<int> afterDelete = list.toVector();
    EXPECT_TRUE(afterDelete.empty());
    
    list.createList({6, 7});
    std::vector<int> newList = list.toVector();
    EXPECT_EQ(newList, std::vector<int>({6, 7}));
}