#include <iostream>
#include <vector>
#include <bit>

using namespace std;

void update(long k, long x, vector<long>& tree) {
    long n = tree.size() / 2;
    k += n - 1;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
	    tree[k] = max(tree[k * 2], tree[k * 2 + 1]);
    }
}

long findFirstGreater(long num, vector<long>& tree) {
    long n = tree.size() / 2 - 1;
    long i = 1;

    while (i <= n) {
        i *= 2;
        if (tree[i] < num) {
            i += 1;
        }

    }
    return i - n;
}

int main() {
    ulong n;
    cin >> n;

    vector<long> tree(__bit_ceil(n)*2);

    long maxLen = 0;
    long index = 1;
    for (ulong i = 0; i < n; i++) {
        long x;
        cin >> x;
        if (x > tree[1]) {
            maxLen += 1;
            update(index, x, tree);
            index += 1;
        } else if (x < tree[1]) {
            long index = findFirstGreater(x, tree);
            update(index, x, tree);
        }
    }

    cout << maxLen << endl;
}
 
