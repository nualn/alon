#include <iostream>
#include <vector>

using namespace std;

void update(long k, long x, vector<long>& tree) {
    long n = tree.size() / 2;
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

long querySum(long a, long b, vector<long>& tree) {
    long n = tree.size() / 2;
    a += n;
    b += n;
    long s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b--];
        a /= 2;
        b /= 2;
    }
    return s;
}

int main() {
    long n, q;
    cin >> n >> q;
    vector<long> arr(2 * n);

    for (long i = 1; i <= n; i++) {
        long x;
        cin >> x;
        update(i, x, arr);
    }

    vector<vector<long>> cmds(q);

    for (long i = 0; i < q; i++) {
        long type, a, b;
        cin >> type >> a >> b;
        cmds[i] = vector<long>{ type, a, b };
    }

    for (ulong i = 0; i < cmds.size(); i++) {
        vector<long> cmd = cmds[i];
        if (cmd[0] == 1) {
            update(cmd[1], cmd[2], arr);
        } else {
            long res = querySum(cmd[1], cmd[2], arr);
            cout << res << endl;
        }
    }
}