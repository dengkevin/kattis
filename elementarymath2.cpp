#include <bits/stdc++.h>

using namespace std;

//check if a match can be made
long long match(long long current, vector<vector<long long>>& adj, vector<long long>& left, vector<long long>& right, vector<long long>& visited) {
    if (visited[current]) {
        return 0;
    }

    visited[current] = 1;

    for (auto u : adj[current]) {
        if (right[u] == -1) {
            left[current] = u;
            right[u] = current;
            return 1;
        }
        else if (match(right[u], adj, left, right, visited)) {
            left[current] = u;
            right[u] = current;
            return 1;
        }
    }

    return 0;
}

int main() {
    //read in n, define relevant data structures
    long long n; cin >> n;
    vector<pair<long long,long long>> number_pair;
    vector<vector<long long>> adj;
    adj.resize(n);

    unordered_map<long long,long long> pairings;
    vector<long long> nums;
    long long count = 0;

    //read in data and get possible +, -, * value combos in graph
    long long a, b;
    for (long long i = 0; i < n; i++) {
        cin >> a >> b;
        pair<long long,long long> pairing;
        pairing.first = a;
        pairing.second = b;
        number_pair.push_back(pairing);

        //for each number pairing, if it is not in the map, we add it to the map showing that this is a unique value obtained
        //for addition
        long long add_result = pairing.first + pairing.second;
        if (pairings.count(add_result) == 0) {
            pairings[add_result] = count;
            count++;
            nums.push_back(add_result);
        }

        adj[i].push_back(pairings[add_result]);

        //for subtraction
        long long subtract_result = pairing.first - pairing.second;
        if (pairings.count(subtract_result) == 0) {
            pairings[subtract_result] = count;
            count++;
            nums.push_back(subtract_result);
        }

        adj[i].push_back(pairings[subtract_result]);

        //for multiplication
        long long multiply_result = pairing.first * pairing.second;
        if (pairings.count(multiply_result) == 0) {
            pairings[multiply_result] = count;
            count++;
            nums.push_back(multiply_result);
        }

        adj[i].push_back(pairings[multiply_result]);
    }

    //bipartite match pairing
    vector<long long> match_pairing;
    vector<long long> right;
    vector<long long> visited;
    match_pairing.resize(n);
    right.resize(count);
    visited.resize(n);
    fill(match_pairing.begin(), match_pairing.end(), -1);
    fill(right.begin(), right.end(), -1);
    long long good = 1;
    while (good) {
        good = 0;
        fill(visited.begin(), visited.end(), 0);
        for (long long i = 0; i < n; i++) {
            if (match_pairing[i] == -1) {
                //recursively check for match
                good = good | match(i, adj, match_pairing, right, visited);
            }
        }
    }

    //checking for valid solutions
    long long total = 0;
    for (long long i = 0; i < n; i++) {
        if (match_pairing[i] != -1) {
            total++;
        }
    }

    //if valid solution, prlong long out a valid solution.
    if (total == n) {
        for (long long i = 0; i < n; i++) {
            cout << number_pair[i].first << " ";

            if (number_pair[i].first + number_pair[i].second == nums[match_pairing[i]]) {
                cout << "+";
            }
            else if (number_pair[i].first - number_pair[i].second == nums[match_pairing[i]]) {
                cout << "-";
            }
            else {
                cout << "*";
            }
            cout << " " << number_pair[i].second << " = " << nums[match_pairing[i]] << endl;
        }
    }
    else {
        cout << "impossible" << endl;
    }
    return 0;
}