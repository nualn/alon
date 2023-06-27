#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    int iters = 0;
    std::set<int> seen;

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;

        if (!seen.contains(num - 1)) iters++;

        seen.insert(num);
    }

    std::cout << iters << '\n';
}