#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h; cin >> n >> h;
    int low, high;
    //will store the amount to break at height i
    vector<int> bottoms(h + 1);
    //will store the amount to break at height i
    vector<int> tops(h + 1);
    fill(bottoms.begin(), bottoms.end(), 0);
    fill(tops.begin(), tops.end(), 0);
    for (int i = 0; i < n / 2; i++) {
        cin >> low >> high;
        bottoms[low]++;
        tops[h - high + 1]++;
    }
    //calculate running sum of amount to break
    //for bottom it is in reverse order
    for (int i = bottoms.size() - 2; i >= 0; i--) {
        bottoms[i] = bottoms[i] + bottoms[i + 1];
    }
    //for top it is in order
    for (int i = 1; i < tops.size(); i++) {
        tops[i] = tops[i] + tops[i - 1];
    }
    //calculate total hit for each height and find min.
    //keep track of frequency too.
    int min = INT_MAX;
    int freq = 0;
    for (int i = 1; i <= h; i++) {
        if (bottoms[i] + tops[i] < min) {
            min = bottoms[i] + tops[i];
            //new min, reset freq
            freq = 1;
        }
        else if (bottoms[i] + tops[i] == min) {
            freq++;
        }
    }
    cout << min << " " << freq << endl;
    return 0;
}