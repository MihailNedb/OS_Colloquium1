#include <gtest/gtest.h>
#include "func.h"

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
    Node* head = createList(input);
    Node* reversed = reverseRec(head);
    
    std::vector<int> result;
    Node* current = reversed;
    while (current != nullptr) {
        result.push_back(current->data);
        current = current->next;
    }
    
    std::vector<int> expected = {5, 4, 3, 2, 1};
    EXPECT_EQ(result, expected);
    deleteL(reversed);
}

TEST(ReverseRecTest, SingleElement) {
    std::vector<int> input = {42};
    Node* head = createList(input);
    Node* reversed = reverseRec(head);
    
    EXPECT_EQ(reversed->data, 42);
    EXPECT_EQ(reversed->next, nullptr);
    deleteL(reversed);
}