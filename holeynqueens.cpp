#include <bits/stdc++.h>

using namespace std;

//backtracking for n-queens
//we reduce problem complexity by iterating through rows, making sure one queen per row
void backtrack(set<int>& col, set<int>& pos_diag, set<int>& neg_diag, int r, int n, int& count, const vector<pair<int, int>>& holes) {
    //base case: if row reaches the nth row, we terminate and have a solution
    if (r == n) {
        count++;
        return;
    }
    //loop through cols
    for (int c = 0; c < n; c++) {
        //check whether r, c can be a good position for the queen placement
        //it cannot be in the same col or diagonals; cannot be a hole too
        pair<int, int> p = make_pair(r, c);
        if ((col.find(c) != col.end()) || (pos_diag.find(r + c) != pos_diag.end()) || (neg_diag.find(r - c) != neg_diag.end()) || (find(holes.begin(), holes.end(), p) != holes.end())) {
            continue;
        }
        //add new queen placement details
        col.insert(c);
        pos_diag.insert(r + c);
        neg_diag.insert(r - c);
        //backtrack on next row
        backtrack(col, pos_diag, neg_diag, r + 1, n, count, holes);
        //return board to previous since we want to explore all possible combinations
        col.erase(c);
        pos_diag.erase(r + c);
        neg_diag.erase(r - c);
    }
}

//returns number of distinct solutions for n-queens
int solveNQueens(int n, const vector<pair<int, int>>& holes) {
    //keeps track of visited cols
    set<int> col;
    //keeps track of visited pos diag (upwards) via expression row + col
    set<int> pos_diag;
    //keeps track of visited neg diag (downwards) via expression row - col
    set<int> neg_diag;
    int count = 0;
    //brute force backtracking
    backtrack(col, pos_diag, neg_diag, 0, n, count, holes);
    return count;
}

int main() {
    int n, m; cin >> n >> m;
    int solutions;
    //read in input
    while (!(n == 0 && m == 0)) {
        //keep track of holes
        vector<pair<int, int>> holes(m);
        //total number of distinct solutions
        solutions = 0;
        //construct holes
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            pair<int, int> p = make_pair(a, b);
            holes[i] = p;
        }
        //n-queens
        solutions = solveNQueens(n, holes);
        //print out solution count
        cout << solutions << endl;
        //read in new input
        cin >> n >> m;
    }
    return 0;
}