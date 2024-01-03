#include <iostream>
#include <vector>

using namespace std;

void set(long pos, long val, vector<long>& tree) {
    long n = tree.size() / 2;
    long k = pos + n;
    tree[k] = val;
}

long getValue(long pos, vector<long>& tree) {
    long n = tree.size() / 2;
    long k = pos + n;
    long res = tree[k];
    for (k /= 2; k >= 1; k /= 2) {
	    res += tree[k];
    }

    return res;
}

void updateRange(long a, long b, long u, vector<long>& tree) {
    long n = tree.size() / 2;
    a += n;
    b += n;
    while (a <= b) {
        if (a % 2 == 1) tree[a++] += u;
        if (b % 2 == 0) tree[b--] += u;
        a /= 2;
        b /= 2;
    }
}

int main() {
    long n, q;
    cin >> n >> q;
    vector<long> arr(2 * n);

    for (long i = 1; i <= n; i++) {
        long x;
        cin >> x;
        set(i, x, arr);
    }

    for (long i = 0; i < q; i++) {
        long type;
        cin >> type;
        if (type == 1) {
            long a, b, u;
            cin >> a >> b >> u;
            updateRange(a, b, u, arr);
        } else if (type == 2) {
            long k;
            cin >> k;
            cout << getValue(k, arr) << endl;
        }
    }
}

