#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, p, x, l; cin >> c >> p >> x >> l;
    int a, b;
    //denotes there is an active edge if second number is 1. used for earlier solution. no longer needed.
    vector<pair<int, int>> adj[c + 1];
    unordered_map<int, int> freq;
    unordered_map<int, int> freq2;
    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        adj[a].push_back({b, 1});
        adj[b].push_back({a, 1});
        //update freq
        if (freq.find(a) == freq.end()) {
            freq[a] = 1;
            freq2[a] = 1;
        }
        else {
            freq[a]++;
            freq2[a]++;
        }
        if (freq.find(b) == freq.end()) {
            freq[b] = 1;
            freq2[b] = 1;
        }
        else {
            freq[b]++;
            freq2[b]++;  
        }
    }

    queue<int> q;
    vector<int> left_countries(c + 1);
    fill(left_countries.begin(), left_countries.end(), 0);
    left_countries[l] = 1;
    for (int i = 0; i < adj[l].size(); i++) {
        freq2[adj[l][i].first]--;
        q.push(adj[l][i].first);
    }
    while (!q.empty()) {
        int leave = q.front();
        q.pop();
        if (left_countries[leave] == 1) {
            continue;
        }
        if (freq2[leave] <= freq[leave] / 2) {
            left_countries[leave] = 1;
            for (int i = 0; i < adj[leave].size(); i++) {
                freq2[adj[leave][i].first]--;
                if (left_countries[adj[leave][i].first] != 1) {
                    q.push(adj[leave][i].first);
                }
            }
        }
    }
    if (left_countries[x] == 1) {
        cout << "leave" << endl;
    }
    else {
        cout << "stay" << endl;
    }
    return 0;
}