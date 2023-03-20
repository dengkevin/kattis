#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> max_left(n);
    vector<int> min_right(n);
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[i] = a;
    }
    max_left[0] = arr[0];
    min_right[min_right.size() - 1] = arr[arr.size() - 1];
    //calculate max_left
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_left[i - 1]) {
            max_left[i] = arr[i];
        }
        else {
            max_left[i] = max_left[i - 1];
        }
    }
    //calculate min_right
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] < min_right[i + 1]) {
            min_right[i] = arr[i];
        }
        else {
            min_right[i] = min_right[i + 1];
        }
    }
    int total = 0;
    for (int i = 0; i < arr.size(); i++) {
        if ((arr[i] <= min_right[i]) && (arr[i] >= max_left[i])) {
            total++;
        }
    }
    cout << total << endl;
    return 0;
}