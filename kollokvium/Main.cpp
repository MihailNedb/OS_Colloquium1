#include "func.h"
#include <iostream>

int main() {
    std::vector<long long> f = genF(5);
    for (auto x : f) std::cout << x << " ";
    std::cout << std::endl;

    std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4};
    for (auto x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    std::vector<int> noDup = removeDup(vec);
    for (auto x : noDup) std::cout << x << " ";
    std::cout << std::endl;

    std::vector<int> listVals = {1, 2, 3, 4, 5};
    Node* head = createList(listVals);
    printL(head);
    
    Node* reversed = reverseRec(head);
    printL(reversed);
    
    deleteL(reversed);
    
    return 0;
}