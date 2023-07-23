#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int leastSplits(int a, int b, std::vector<std::vector<int>>& memo) {
    if (a > b) {
        swap(&a, &b);
    }

    if (a == b) return 0;
    if (memo[a][b] != 0) return memo[a][b];

    int currMin = std::numeric_limits<int>::max();
    for (int i = 1; i < a; i++) {
        int splits = leastSplits(i, b, memo) + leastSplits(a - i, b, memo) + 1;
        currMin = std::min(currMin, splits);
    }

    for (int i = 1; i < b; i++) {
        int splits = leastSplits(a, i, memo) + leastSplits(a, b - i, memo) + 1;
        currMin = std::min(currMin, splits);
    }

    memo[a][b] = currMin;
    return currMin;
}

int main() {
    int a, b;
    std::cin >> a >> b;

    if (a > b) {
        swap(&a, &b);
    }

    auto memo = std::vector(a + 1, std::vector<int>(b + 1, 0));

    int res = leastSplits(a, b, memo);
    std::cout << res << std::endl;
}