#include <iostream>
#include <vector>
#include <bit>

using namespace std;

void add(long k, long x, vector<long>& tree) {
    long n = tree.size() / 2;
    k += n - 1;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
	    tree[k] += 1;
    }
}

long remove(long idx, vector<long>& tree) {
    long n = tree.size() / 2 - 1;
    long i = 1;

    while (i <= n) {
        i *= 2;
        if (tree[i] < idx) {
            idx -= tree[i]; 
            i += 1;
        }

    }

    long res = i - n;

    for (; i >= 1; i /= 2) {
	    tree[i] -= 1;
    }

    return res;
}

int main() {
    ulong n;
    cin >> n;

    vector<long> counts(__bit_ceil(n)*2);
    vector<long> digits(n+1);

    for (ulong i = 1; i <= n; i++) {
        long x;
        cin >> x;
        add(i, 1, counts);
        digits[i] = x;
    }

    vector<long> indices(n);

    for (ulong i = 0; i < n; i++) {
        cin >> indices[i];
    }

    for (ulong i = 0; i < n; i++) {
        long index = remove(indices[i], counts);
        cout << digits[index] << " ";
    }
    cout << endl;
}
 
