
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

const int modulus = 1000000007;

int main() {
    int t;
    std::cin >> t;

    int max = 0;
    auto ns = std::vector<int>(t);
    for (int i = 0; i < t; i++) {
        std::cin >> ns[i];
        if (max < ns[i]) max = ns[i];
    }

    auto memo = std::vector<std::pair<long, long>>(max);

    memo[0] = { 1, 1 };

    for (int i = 1; i < max; i++) {
        auto prev = memo[i - 1];
        std::pair<long, long> res;
        res.first = (prev.first * 2 + prev.second) % modulus;
        res.second = (prev.first + prev.second * 4) % modulus;

        memo[i] = res;
    }

    for (int i = 0; i < t; i++) {
        auto res = memo[ns[i] - 1];
        std::cout << (res.first + res.second) % modulus << std::endl;
    }
}