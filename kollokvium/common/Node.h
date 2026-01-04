#ifndef NODE_H
#define NODE_H
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
#endif