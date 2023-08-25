#include <iostream>
#include <string>

long long memo[20][10][2];

long long solve(std::string& num, uint pos, int prev, bool leadz, bool bound) {
    if (pos >= num.length()) return 1;

    if (!bound && memo[num.length() - pos][prev][leadz]) {
        return memo[num.length() - pos][prev][leadz];
    }

    int upperBound = bound ? num[pos] - '0' : 9;

    long long res = 0;
    for (int i = 0; i <= upperBound; i++) {
        if (i == prev && !leadz) continue;

        res += solve(num, pos + 1, i, leadz && i == 0, bound && i == upperBound);
    }

    if (!bound) memo[num.length() - pos][prev][leadz] = res;
    return res;
}

int main() {
    long long a, b;
    std::cin >> a >> b;

    std::string bString = std::to_string(b);
    std::string aString = std::to_string(a - 1);

    long long res =
        solve(bString, 0, 0, true, true)
        - solve(aString, 0, 0, true, true);

    std::cout << res << std::endl;
}