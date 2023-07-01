#include <iostream>
#include <vector>
#include <map>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> starts;
    std::vector<std::pair<int, int>> ends;


    for (int visitor = 0; visitor < n; visitor++) {
        int start, end;
        std::cin >> start >> end;

        starts.push_back({ start, visitor });
        ends.push_back({ end, visitor });
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    std::vector<int> res(n);
    std::map<int, int> rooms;
    std::set<int> fRooms;

    int maxConcurr = 0;

    auto pStart = starts.begin();
    auto pEnd = ends.begin();

    for (int i = 0; i < 2 * n; i++) {
        if (pStart == starts.end() || pEnd->first < pStart->first) {
            int room = rooms[pEnd->second];
            fRooms.insert(room);
            rooms.erase(pEnd->second);
            pEnd++;
        } else {
            int room;
            if (fRooms.empty()) {
                maxConcurr++;
                room = maxConcurr;
            } else {
                room = *fRooms.begin();
                fRooms.erase(fRooms.begin());
            }
            rooms[pStart->second] = room;
            res[pStart->second] = room;
            pStart++;
        }
    }

    std::cout << maxConcurr << std::endl;
    for (auto x : res) std::cout << x << ' ';
    std::cout << std::endl;
}