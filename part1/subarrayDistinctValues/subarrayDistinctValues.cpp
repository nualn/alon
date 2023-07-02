#include <iostream>
#include <vector>
#include <set>
#include <map>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums;

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    // sliding window
    long count = 0;
    auto subStart = nums.begin();
    auto subEnd = subStart;
    std::map<int, int>uniqueNums{ { *subStart, 1 } };
    for (int i = 0; i < n; i++) {
        while (uniqueNums.size() <= k && subEnd < nums.end()) {
            subEnd++;
            uniqueNums[*subEnd]++;
        }
        int subLength = subEnd - subStart;
        count += subLength;

        uniqueNums[*subStart]--;
        if (uniqueNums[*subStart] == 0) uniqueNums.erase(*subStart);
        subStart++;
    }

    std::cout << count << std::endl;
}