#include <bits/stdc++.h>

using namespace std;

//checks if current country has same color
bool isSafe(int curr, int countries, int c, vector<vector<int>>& adj, vector<int>& colors) {
    //iterate through all neighboring
    for (auto i : adj[curr]) {
        //if c = colors[i], then it is not safe
        if (c == colors[i]) {
            return false;
        }
    }
    //if reached here, then it is safe
    return true;
}

//backtracking for graph colorings
void graphColour(int curr, int countries, int numColor, vector<vector<int>>& adj, vector<int>& colors, bool& hasEnough) {
    //iterate through all colors
    for (int c = 1; c <= numColor; c++) {
        //check if neighboring nodes use the same color or not to curr
        if (isSafe(curr, countries, c, adj, colors)) {
            //if safe, set c to curr color
            colors[curr] = c;
            //if not all countries have been visited, backtrack
            if (curr + 1 < countries) {
                graphColour(curr + 1, countries, numColor, adj, colors, hasEnough);
                //return colors array to default
                colors[curr] = 0;
            }
            else {
                //reached the end and colors satisfy
                hasEnough = true;
                return;
            }
        }
    }
}

int main() {
    int t; cin >> t;
    //go through all test cases
    for (int i = 0; i < t; i++) {
        int c, b; cin >> c >> b;
        //edge case
        if (b == 0) {
            cout << "1" << endl;
            continue;
        }
        //adjacency list
        vector<vector<int>> adj(c);
        //go through all borders
        for (int j = 0; j < b; j++) {
            //construct adjacency list
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool hasEnough = 0;
        //for colorings 1-4, iterate through scenario
        for (int j = 1; j <= 4; j++) {
            //colors is the array to keep track of colors used by different countries
            vector<int> colors(c, 0);
            //hasEnough is a boolean determining whether j colors is enough to color the graph
            hasEnough = 0;
            //coloring backtracking starting at country 0, going through all countries c, with j colors
            graphColour(0, c, j, adj, colors, hasEnough);
            if (hasEnough) {
                cout << j << endl;
                break;
            }
        }
        //if hasEnough, then we continue to next case
        if (hasEnough) {
            continue;
        }
        //if passed over 4 colors, print many
        cout << "many" << endl;
    }
    return 0;
}