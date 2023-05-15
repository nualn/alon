#include <iostream>

int main() {
    int n;
    int prev;
    int curr;
    long res = 0;
    std::cin >> n >> prev;

    for (int i = 1; i < n; i++) {
        std::cin >> curr;
        if (curr < prev) {
            res += prev - curr;
        } else {
            prev = curr;
        }

    }

    std::cout << res << '\n';
}