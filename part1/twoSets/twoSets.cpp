#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> one;
    std::vector<int> two;

    std::cin >> n;

    int diff = 0;

    for (int i = n; i > 0; i--) {
        if (diff < 0) {
            one.push_back(i);
            diff += i;
        } else {
            two.push_back(i);
            diff -= i;
        }
    }

    if (diff == 0) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
        return 0;
    }

    std::cout << one.size() << '\n';
    for (int x : one) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::cout << two.size() << '\n';
    for (int x : two) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

}