#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<long> getSubsetSums(vector<int>& arr) {
    vector<long> sums{ 0 };

    for (int num : arr) {
        int iterations = sums.size();
        for (int i = 0; i < iterations; i++) {
            sums.push_back(sums[i] + num);
        }
    }

    sort(sums.begin(), sums.end());
    return sums;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> subArray1(n / 2);
    vector<int> subArray2(n - (n / 2));

    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            subArray1[i] = nums[i];
        } else {
            subArray2[i - (n / 2)] = nums[i];
        }
    }

    auto subSetSums1 = getSubsetSums(subArray1);
    auto subSetSums2 = getSubsetSums(subArray2);

    u_long p1 = 0;
    long p2 = subSetSums2.size() - 1;

    long res = 0;
    while (p1 < subSetSums1.size() && p2 >= 0) {
        if (subSetSums1[p1] + subSetSums2[p2] == x) {
            long c1 = 0;
            long c2 = 0;
            while (p1 < subSetSums1.size() && subSetSums1[p1] + subSetSums2[p2] == x) {
                c1++;
                p1++;
            }
            p1--;
            while (p2 >= 0 && subSetSums1[p1] + subSetSums2[p2] == x) {
                c2++;
                p2--;
            }
            res += c1 * c2;
        } else if (subSetSums1[p1] + subSetSums2[p2] < x) {
            p1++;
        } else if (subSetSums1[p1] + subSetSums2[p2] > x) {
            p2--;
        }
    }
    cout << res << endl;
}