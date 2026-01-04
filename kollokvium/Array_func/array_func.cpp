#include "array_func.h"

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