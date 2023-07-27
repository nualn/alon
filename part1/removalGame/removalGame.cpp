#include <iostream>
#include <vector>

std::pair<long, long> bestScore(
    std::vector<int>& nums,
    int p1,
    int p2,
    bool isFirstsTurn,
    std::vector < std::vector<std::pair<bool, std::pair<long, long>>>>& memo
) {

    if (p1 > p2) return { 0,0 };
    if (memo[p1][p2 - p1].first) return memo[p1][p2 - p1].second;

    auto score = bestScore(nums, p1 + 1, p2, !isFirstsTurn, memo);
    auto score2 = bestScore(nums, p1, p2 - 1, !isFirstsTurn, memo);

    std::pair<long, long> res;
    if (isFirstsTurn) {
        score.first += nums[p1];
        score2.first += nums[p2];

        if (score.first > score2.first) res = score;
        else res = score2;
    } else {
        score.second += nums[p1];
        score2.second += nums[p2];

        if (score.second > score2.second) res = score;
        else res = score2;
    }

    memo[p1][p2 - p1] = { true, res };
    return res;
}

int main() {
    int n;
    std::cin >> n;

    auto nums = std::vector<int>(n, 0);
    for (int i = 0; i < n; i++) std::cin >> nums[i];

    std::vector<std::vector<std::pair<bool, std::pair<long, long>>>> memo;
    for (int i = 0; i < n; i++) {
        memo.push_back(std::vector<std::pair<bool, std::pair<long, long>>>(n - i, { false, {0,0} }));
    }

    auto res = bestScore(nums, 0, nums.size() - 1, true, memo);

    std::cout << res.first << std::endl;
}