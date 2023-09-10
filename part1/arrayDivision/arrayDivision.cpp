#include <iostream>
#include <vector>
#include <algorithm>

bool canDivide(std::vector<int>& arr, int k, long maxSum) {
    int subArrCount = 1;
    long currCount = 0;

    for (int num : arr) {
        if (num > maxSum) return false;
        if (currCount + num > maxSum) {
            currCount = num;
            subArrCount++;
        } else {
            currCount += num;
        }
    }

    return subArrCount <= k;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    long leftLimit = 0;
    long rightLimit = n * 1e9;
    while (leftLimit < rightLimit) {
        long midPoint = (leftLimit + rightLimit) / 2;
        if (canDivide(nums, k, midPoint)) {
            rightLimit = midPoint;
        } else {
            leftLimit = midPoint + 1;
        }
    }

    std::cout << leftLimit << std::endl;
}