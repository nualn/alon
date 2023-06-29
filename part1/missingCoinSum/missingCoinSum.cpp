#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n <= 0) return -1;

    std::vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        nums[i] = num;
    }

    sort(nums.begin(), nums.end());

    long smallest = 1;
    for (auto num : nums) {
        if (num > smallest) break;
        smallest += num;
    };

    std::cout << smallest << std::endl;
}