#include "Math_func.h"

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