#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	graph[a].push_back(b);
	graph[b].push_back(a);
    }

    vector<bool> visited(n);
    vector<vector<int>> subgraphs;
    for (int next = 0; (uint)next < visited.size(); next++) {
	if (visited[next]) continue;

	vector<int> sg;
	queue<int> q;
	q.push(next);
	visited[next] = true;

	while (!q.empty()) {
	    int node = q.front();
	    sg.push_back(node);
	    for (auto neighbor : graph[node]) {
		if (!visited[neighbor]) {
		    visited[neighbor] = true;
		    q.push(neighbor);
		}
	    }
	    q.pop();
	}

	subgraphs.push_back(sg);
    }

    int mid = subgraphs[0][0];

    cout << subgraphs.size() - 1 << endl;
    for (uint i = 1; i < subgraphs.size(); i++) {
	cout << (mid + 1) << " " << (subgraphs[i][0] + 1) << endl;
    }

}
