#include <iostream>
#include <vector>
#include <algorithm>

long productsInTime(std::vector<int>& factories, long time) {
    long res = 0;
    for (int factory : factories) {
        res += time / factory;
    }

    return res;
}

int main() {
    long n, t;
    std::cin >> n >> t;

    std::vector<int> k(n);
    long avg = 1;
    for (long i = 0; i < n; i++) {
        std::cin >> k[i];
        avg += k[i] / n;
    }

    long searchStartTime = 0;
    for (long searchSize = t * avg; searchSize > 0; searchSize /= 2) {
        while (productsInTime(k, searchStartTime + searchSize) < t) {
            searchStartTime += searchSize;
        }
    }
    searchStartTime += 1;

    std::cout << searchStartTime << std::endl;
}