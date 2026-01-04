#include "Array_func/array_func.h"
#include "LinkedList/LinkedList.h"
#include "Math_func/Math_func.h"

#include <iostream>

int main() {
    long long n;
    std::cout << "1. Enter a number to see all factorials up to n! : ";
    std::cin >> n;
    std::vector<long long> f = genF(n);
    
    for (int i = 0; i < f.size(); i++)
    {
       std::cout << i+1 << "! = " << f[i]<<"    ";
    }
    std::cout << std::endl;

    
    std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4};
    std::cout <<"2. Vector with duplicates: ";
    for (auto x : vec) std::cout << x << " ";
    std::cout << std::endl;
    std::cout <<"   Vector without duplicates: ";
    std::vector<int> noDup = removeDup(vec);
    for (auto x : noDup) std::cout << x << " ";
    std::cout << std::endl;

    LinkedList list;
    std::vector<int> listVals = {1, 2, 3, 4, 5};
    list.createList(listVals);
     std::cout <<"3. LinkedList: ";
    list.printL();
    list.reverseRec();
    std::cout <<"   Reversed LinkedList: ";
    list.printL();
    
    return 0;
}