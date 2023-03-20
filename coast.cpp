#include <iostream>
#include <vector>
using namespace std;

void flood(vector<vector<int>> &v, int i, int j, int n, int m) {
    /*if out of bounds, stop*/
    if (i < 0 || j < 0 || i >= n + 2 || j >= m + 2) {
        return;
    }
    /*if land, stop*/
    if (v[i][j] != 0) {
        return;
    }
    /*mark sea as visited*/
    v[i][j] = -1;
    //if (v[i + 1][j] != -1) {
        flood(v, i + 1, j, n, m);
    //}
    //if (v[i - 1][j] != -1) {
        flood(v, i - 1, j, n, m);
    //}
    //if (v[i][j + 1] != -1) {
        flood(v, i, j + 1, n, m);
    //}
    //if (v[i][j - 1] != -1) {
        flood(v, i, j - 1, n, m);
    //}
}

int main() {
    /*read in the data*/
    int n, m; cin >> n >> m;
    string row;
    int square = 0;
    vector<vector<int>> v;
    v.resize(n + 2, vector<int>(m + 2));
    for (int i = 1; i < v.size() - 1; i++) {
        cin >> row;
        for (int j = 1; j < v[i].size() - 1; j++) {
            v[i][j] = row[square] - '0';
            square++;
        }
        square = 0;
    }
    /*for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/
    /*floodfill from outer edges (not from border though)*/
    for (int i = 1; i <= n; i++) {
        flood(v, i, 1, n, m);
        flood(v, i, m, n, m);
    }
    
    for (int i = 1; i <= m; i++) {
        flood(v, 0, i, n, m);
        flood(v, n, i, n, m);
    }
    /*cout << endl;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/
    /*count coastal length*/
    int length = 0;
    for (int i = 1; i < v.size() - 1; i++) {
        for (int j = 1; j < v[i].size() - 1; j++) {
            if (v[i][j] == 1) {
                if (v[i - 1][j] == -1) {
                    length++;
                }
                if (v[i + 1][j] == -1) {
                    length++;
                }
                if (v[i][j - 1] == -1) {
                    length++;
                }
                if (v[i][j + 1] == -1) {
                    length++;
                }
            }
        }
    }
    cout << length << endl;
    return 0;
}