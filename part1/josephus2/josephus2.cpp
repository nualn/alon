#include <iostream>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


int main() {
    int n, k;
    std::cin >> n >> k;
    indexed_set c;
    for (int i = 1; i <= n; i++) c.insert(i);

    int offset = 0;
    for (int i = 0; i < n; i++) {
        offset += k;
        offset %= c.size();

        auto removed = c.find_by_order(offset);
        std::cout << *removed << ' ';
        c.erase(*removed);
    }

    std::cout << std::endl;
}
