#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	//adj list
	vector<pair<int, int>> adj[n];

	//construct the graph
	int a, b, d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}

	//run Dijkstra's from source = Amsterdam
	vector<int> distance(n);
	priority_queue<pair<int, int>> pq;
	vector<int> processed(n);
	vector<int> parent(n);

	for (int i = 0; i < n; i++) {
		distance[i] = INT_MAX;
	}
	distance[1] = 0;
	//pq contains pairs in the form {-d, x} where current distance to x is d
	pq.push({0, 1});
	while(!pq.empty()) {
		int a = pq.top().second;
		pq.pop();
		if (processed[a]) {
			continue;
		}
		processed[a] = true;
		for (auto u : adj[a]) {
			int b = u.first;
			int w = u.second;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				//this is for maintaining the actual shortest path
				parent[b] = a;
				pq.push({-distance[b], b});
			}
		}
	}
	/*
	//Delete the paths that contain signs
	int start = 0;
	//stop indicates when we have hit Amsterdam
	bool stop = false;
	while (!stop) {
		if (parent[start] == 1) {
			stop = true;
		}
		for (int i = 0; i < adj[start].size(); i++) {
			if (adj[start][i].first == parent[start]) {
				adj[start].erase(adj[start].begin() + i);
				break;
			}
		}
		start = parent[start];
	}*/
	
	
	//Delete the paths that contain signs
	for (int i = 0; i < parent.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (adj[i][j].first == parent[i]) {
				adj[i].erase(adj[i].begin() + j);
				break;
			}
		}
	}

	/*//verification purposes for adj list [to amsterdam]
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (auto u : adj[i]) {
			cout << u.first << " ";
		}
		cout << endl;
	}
	cout << "BREAK" << endl;*/

	//0 to 1 find path
	parent.clear();
	processed.clear();
	parent.resize(n);
	processed.resize(n);
	stack<int> s;
	s.push(0);
	processed[0] = true;
	bool reached_end = false;
	while (!s.empty()) {
		int a = s.top();
		s.pop();
		if (a == 1) {
			reached_end = true;
			break;
		}
		for (auto u : adj[a]) {
			if (processed[u.first]) {
				continue;
			}
			processed[u.first] = true;
			parent[u.first] = a;
			s.push(u.first);
		}
	}

	if (reached_end == false) {
		cout << "impossible";
	}
	else {
		vector<int> path;
		int start = 1;
		bool end_path = false;
		while (!end_path) {
			path.push_back(start);
			if (parent[start] == 0) {
				end_path = true;
			}
			start = parent[start];
		}
		cout << path.size() + 1 << " " << 0;
		for (int i = path.size() - 1; i >= 0; i--) {
			cout << " " << path[i];
		}
	}
	cout << endl;
	return 0;
}

/*
1. Dijkstra's to find shortest path. 
2. Remove edge going to from nth road to Amsterdam
3. DFS 0 to 1 and find path
*/