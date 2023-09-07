#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;

    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());

    int median = nums[n / 2];

    long res = 0;
    for (int i = 0; i < n; i++) {
        res += std::abs(nums[i] - median);
    }

    std::cout << res << std::endl;
}