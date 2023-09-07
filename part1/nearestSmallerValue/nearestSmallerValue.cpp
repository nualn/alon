#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    std::vector<int> stack;
    std::vector<int> res(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];

        while (!stack.empty() && v[stack.back()] >= v[i]) {
            stack.pop_back();
        }

        int nsv;
        if (stack.empty()) {
            nsv = -1;
        } else {
            nsv = stack.back();
        }
        res[i] = nsv;

        stack.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        std::cout << res[i] + 1 << ' ';
    }
    std::cout << std::endl;
}