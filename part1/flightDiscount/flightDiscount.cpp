#include <iostream> 
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

#define int long long

using namespace std;

struct FlightPath {
    int cost;
    int node;
    bool coupon;

    FlightPath(int cost, int node, bool coupon)
	: cost(cost)
	, node(node)
	, coupon(coupon)
    {
    }
};

signed main() {	
    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_map<int, int>> graph;
    for (int i = 0; i < m; i++) {
	int a, b, c;
	cin >> a >> b >> c;
	if (graph[a].contains(b)) {
	    graph[a][b] = min(graph[a][b], c);
	} else {
	    graph[a][b] = c;
	}
    }

    auto cmp = [] (const FlightPath l, const FlightPath r) { 
	return l.cost > r.cost;
    };
    priority_queue<FlightPath, vector<FlightPath>, decltype(cmp)> q;
    q.push(FlightPath(0, 1, true));
    
    unordered_map<int, int> lowestCostWithCoupon;
    unordered_map<int, int> lowestCostNoCoupon;
    unordered_set<int> visitedWithCoupon;
    unordered_set<int> visitedNoCoupon;

    while (q.top().node != n) {
	FlightPath curr = q.top();
	q.pop();
	if (curr.coupon && visitedWithCoupon.find(curr.node) != visitedWithCoupon.end()) continue;
	if (!curr.coupon && visitedNoCoupon.find(curr.node) != visitedNoCoupon.end()) continue;
	if(curr.coupon) visitedWithCoupon.insert(curr.node);
	if(!curr.coupon) visitedNoCoupon.insert(curr.node);

	for (auto neighbor : graph[curr.node]) {

	    if (!curr.coupon) {
		if (!lowestCostNoCoupon.contains(neighbor.first) || curr.cost + neighbor.second < lowestCostNoCoupon[neighbor.first]) {
		    lowestCostNoCoupon[neighbor.first] = curr.cost + neighbor.second;
		    q.push(FlightPath(curr.cost + neighbor.second, neighbor.first, curr.coupon));
		}
	    }

	    if (curr.coupon) {
		if (!lowestCostWithCoupon.contains(neighbor.first) || curr.cost + neighbor.second < lowestCostWithCoupon[neighbor.first]) {
		    lowestCostWithCoupon[neighbor.first] = curr.cost + neighbor.second;
		    q.push(FlightPath(curr.cost + neighbor.second, neighbor.first, curr.coupon));
		}
		if (!lowestCostNoCoupon.contains(neighbor.first) || curr.cost + neighbor.second / 2 < lowestCostNoCoupon[neighbor.first]) {
		    lowestCostNoCoupon[neighbor.first] = curr.cost + neighbor.second / 2;
		    q.push(FlightPath(curr.cost + neighbor.second / 2, neighbor.first, false));
		}
	    }
	}
    }

    cout << q.top().cost << endl;
}
