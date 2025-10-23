#ifndef FUNC_H
#define FUNC_H

#include <vector>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

std::vector<long long> genF(int n);
std::vector<int> removeDup(const std::vector<int>& arr);
Node* createList(const std::vector<int>& vals);
Node* reverseRec(Node* head);
void printL(Node* head);
void deleteL(Node* head);

#endif