#include <iostream>
#include <vector>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int target = 0;
    for (int i = 0; i <= n; i++) target += i;
    if (target % 2 == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    target /= 2;

    std::vector<std::vector<int>> memo(n, std::vector(target + 1, 0));
    memo[0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            int count = memo[i - 1][j];
            if (i <= j) count += memo[i - 1][j - i];
            memo[i][j] = count % ((int)1e9 + 7);
        }
    }
    std::cout << memo[n - 1][target] << std::endl;
}