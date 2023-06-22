#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::vector<std::pair<int, int>> movies;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int start, end;
        std::cin >> start >> end;
        movies.push_back({start, end});
    }

    sort(movies.begin(), movies.end());


    int count = 0;
    int currEnd = 0;
    for (auto x : movies) {
        int start = x.first;
        int end = x.second;

        if (start >= currEnd) {
            count++;
            currEnd = end;
        } else if (end < currEnd) {
            currEnd = end;
        }
    }

    std::cout << count << std::endl;
}