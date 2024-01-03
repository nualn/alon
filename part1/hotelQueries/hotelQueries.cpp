#include <iostream>
#include <vector>
#include <bit>

using namespace std;

void add(long k, long x, vector<long>& tree) {
    long n = tree.size() / 2;
    k += n - 1;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
	tree[k] = max(tree[2 * k], tree[2 * k + 1]);
    }
}

long queryHotel(long guests, vector<long>& tree) {
    long n = tree.size() / 2 - 1;
    long i = 1;

    if (tree[i] < guests) {
        return 0;
    }

    while (i <= n) {
        i *= 2;
        if (tree[i] < guests) {
            i += 1;
        }
    }
    return i - n;
}

int main() {
    ulong n, m;
    cin >> n >> m;

    vector<long> arr(__bit_ceil(n)*2);

    for (ulong i = 1; i <= n; i++) {
        long x;
        cin >> x;
        add(i, x, arr);
    }

    vector<long> groups(m);

    for (ulong i = 0; i < m; i++) {
        cin >> groups[i];
    }

    for (ulong i = 0; i < m; i++) {
        long hotel = queryHotel(groups[i], arr);
        cout << hotel << " ";
        if (hotel > 0) {
            add(hotel, -groups[i], arr);
        }
    }
    cout << endl;
}
 
