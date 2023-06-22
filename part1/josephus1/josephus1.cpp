#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<bool> v(n, true);

    int pos = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            pos++;
            pos %= n;
            while (!v[pos]) {
                pos++;
                pos %= n;
            }
        }

        std::cout << pos + 1 << ' ';
        v[pos] = false;
    }

    std::cout << std::endl;
}