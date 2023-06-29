#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::multiset<int> h;
    std::vector<int> t(m);

    for (int i = 0; i < n; i++) {
        int ticket;
        std::cin >> ticket;
        h.insert(ticket);
    };
    for (int i = 0; i < m; i++) std::cin >> t[i];

    for (auto max : t) {
        auto it = h.upper_bound(max);
        if (it == h.begin()) {
            std::cout << -1 << std::endl;
            continue;
        }
        it--;

        std::cout << *it << std::endl;
        h.erase(it);
    }
}
