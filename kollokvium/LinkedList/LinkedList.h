#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
#include "../common/Node.h"

class LinkedList {
private:

    Node* head;
    
public:

    LinkedList();
    
    ~LinkedList();
    
    void createList(const std::vector<int>& vals);
    void printL() const;
    void deleteL();
    void reverseRec();

     std::vector<int> toVector() const;
    
};

#endif 