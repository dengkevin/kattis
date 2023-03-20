#include <bits/stdc++.h>

using namespace std;

//declare global vars for accessibility
vector<vector<int>> adj;
vector<vector<int>> cap;
vector<vector<int>> flows;

//Edmonds Karp BFS component from cp-algorithms.com
int bfs(int s, int t, vector<int>& prev) {
    fill(prev.begin(), prev.end(), -1);
    prev[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (prev[next] == -1 && cap[cur][next]) {
                prev[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	adj.resize(n);
	cap.resize(n);
    fill(cap.begin(), cap.end(), vector<int>(n, 0));
	flows.resize(n);
    fill(flows.begin(), flows.end(), vector<int>(n, 0));
    int u, v, c;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cap[u][v] = c;
	}

    //calculate max flow (Edmonds karp algo slightly modified from cp-algorithms.com)
	int maxflow = 0;
    vector<int> prev(n);
	while (bfs(s, t, prev)) {
		int flow = INT_MAX;
        int current = t;
        while (current != s) {
            int parent = prev[current];
			flow = min(flow, cap[parent][current]);
            current = prev[current];
        }
        current = t;
        //update the flows
        while (current != s) {
            int parent = prev[current];
			flows[parent][current] += flow;
			flows[current][parent] -= flow;
			cap[parent][current] -= flow;
			cap[current][parent] += flow;
            current = prev[current];
        }

		maxflow += flow;
	}

    //count the edges and get the flow transport edges
	int edges_used_in_sol = 0;
	vector<pair<int, int>> flow_graph;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flows[i][j] > 0) {
                pair<int, int> edge;
                edge.first = i;
                edge.second = j;
				flow_graph.push_back(edge);
                edges_used_in_sol += 1;
			}
		}
	}

    //print answer
	cout << n << " " << maxflow << " " << edges_used_in_sol << endl;
	for (auto u : flow_graph) {
		cout << u.first << " " << u.second << " " << flows[u.first][u.second] << endl;
	}

	return 0;
}