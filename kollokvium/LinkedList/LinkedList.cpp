#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    deleteL();
}

void LinkedList::createList(const std::vector<int>& vals) {
    deleteL(); 
    
    if (vals.empty()) {
        head = nullptr;
        return;
    }
    
    head = new Node(vals[0]);
    Node* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
}

void LinkedList::printL() const {
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

void LinkedList::deleteL() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* reverseRecHelper(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        return node;
    }
    Node* rev = reverseRecHelper(node->next);
    node->next->next = node;
    node->next = nullptr;
    return rev;
}

void LinkedList::reverseRec() {
    head = reverseRecHelper(head);
}

std::vector<int> LinkedList::toVector() const {
    std::vector<int> result;
    Node* current = head;
    while (current != nullptr) {
        result.push_back(current->data);
        current = current->next;
    }
    return result;
}

