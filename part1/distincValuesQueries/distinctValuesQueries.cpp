#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <bit>

using namespace std;

void update(long pos, long val, vector<long>& tree) {
    long n = tree.size() / 2 - 1;
    pos += n;
    tree[pos] = val;
    for (pos /= 2; pos > 0; pos /= 2) {
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
}

long query(long a, long b, vector<long>& tree) {
    long n = tree.size() / 2 - 1;
    a += n;
    b += n;

    long s = 0;
    while (a <= b) {
        if (a % 2 == 1) {
            s += tree[a++];
        }
        if (b % 2 == 0) {
            s += tree[b--];
        }
        a /= 2;
        b /= 2;
    }
    return s;
}

int main() {
    long n, q; 
    cin >> n >> q;

    vector<long> tree(__bit_ceil(n) * 2);
    vector<long> ans(q);
    
    vector<long> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        long a;
        cin >> a;
        nums[i] = a;
    }

    vector<vector<pair<long, long>>> qs(n+1);
    for (int i = 0; i < q; i++) {
        long a, b; 
        cin >> a >> b;

        qs[a].push_back({b, i});
    }

    unordered_map<long, long> last_idx;
    for (long i = n; i > 0; i--) {
        long val = nums[i];
        if (last_idx.count(val) > 0) update(last_idx[val], 0, tree);
        last_idx[val] = i;
        update(i, 1, tree);

        for (auto q : qs[i]) {
            ans[q.second] = query(i, q.first, tree);
        }
    }

    for (auto a : ans) cout << a << endl;
}
