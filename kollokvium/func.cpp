#include "func.h"
#include <iostream>
#include <algorithm>

std::vector<long long> genF(int n) {
    if (n <= 0) return {};
    std::vector<long long> res;
    long long f = 1;
    for (int i = 1; i <= n; ++i) {
        f *= i;
        res.push_back(f);
    }
    return res;
}

std::vector<int> removeDup(const std::vector<int>& arr) {
    if (arr.empty()) return {};
    std::vector<int> res;
    for (size_t i = 0; i < arr.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < i; ++j) {
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            res.push_back(arr[i]);
        }
    }
    return res;
}

Node* createList(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

Node* reverseRec(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* rev = reverseRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rev;
}

void printL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data;
        if (curr->next != nullptr) {
            std::cout << " -> ";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}

void deleteL(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}