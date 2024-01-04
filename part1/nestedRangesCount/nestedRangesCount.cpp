#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <unordered_map>
#include <bit>
#include <algorithm>

using namespace std;

void add(long pos, long val, vector<long>& tree) {
    long n = tree.size() / 2 - 1;
    pos += n;
    for (; pos > 0; pos /= 2) {
        tree[pos] += val;
    }
}

long query(long a, long b, vector<long>& tree) {
    long n = tree.size() / 2 - 1;
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

struct comp {
    bool operator()(const tuple<long, long, long>& a, 
                    const tuple<long, long, long>& b) const {
        if (get<0>(a) == get<0>(b)) {
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a)< get<0>(b);
    }
};

int main() {
    long n; 
    cin >> n;

    vector<tuple<long, long, long>> intervals;
    set<long> uniqueNums;
    unordered_map<long, long> indexCompression;
    vector<long> tree(__bit_ceil(n * 2) * 2);
    
    for (int i = 0; i < n; i++) {
        long a, b;
        cin >> a >> b;
        tuple<long, long, long> interval = {a, b, i};
        intervals.push_back(interval);
        uniqueNums.insert(a);
        uniqueNums.insert(b);
    }

    sort(intervals.begin(), intervals.end(), comp());

    long index = 1;
    for (long num : uniqueNums) {
        indexCompression[num] = index++;
    }

    vector<long> contains(n);
    for (auto rit = intervals.rbegin(); rit != intervals.rend(); rit++) {
        auto interval = *rit;
        long res = query(1, indexCompression[get<1>(interval)], tree);
        add(indexCompression[get<1>(interval)], 1, tree);
        contains[get<2>(interval)] = res;
    }

    fill(tree.begin(), tree.end(), 0);

    vector<long> containedBy(n);
    for (auto interval : intervals) {
        long res = query(indexCompression[get<1>(interval)], n * 2, tree);
        add(indexCompression[get<1>(interval)], 1, tree);
        containedBy[get<2>(interval)] = res;
    }
    
    for (long res : contains) cout << res << " ";
    cout << endl;
    for (long res : containedBy) cout << res << " ";
    cout << endl;
}
