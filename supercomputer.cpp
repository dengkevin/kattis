#include <bits/stdc++.h>

using namespace std;

int rangeQuery(vector<int>& fenwick, int index) {
    int sum = 0;
    while (index != 0) {
        sum += fenwick[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    int n, k; cin >> n >> k;
    //fenwick tree construction
    //index i denotes the ith switch.
    vector<int> fenwick(n + 1, 0);
    //index i denotes whether ith switch is flipped or not
    vector<int> flip(n + 1, 0);
    //loop through all scenarios
    char query;
    for (int i = 0; i < k; i++) {
        cin >> query;
        //if F, flip switch and update fenwick
        if (query == 'F') {
            int bit; cin >> bit;
            //if flip[bit] == 0, flip on and add
            if (flip[bit] == 0) {
                flip[bit] = 1;
                while (bit < n + 1) {
                    fenwick[bit] += 1;
                    bit += bit & -bit;
                }
            }
            //if flip[bit] == 1, flip off and subtract
            else {
                flip[bit] = 0;
                while (bit < n + 1) {
                    fenwick[bit] -= 1;
                    bit += bit & -bit;
                }
            }

        }
        //if C, count number of flipped inclusively
        else {
            int bit_lower, bit_higher; cin >> bit_lower >> bit_higher;
            int count = rangeQuery(fenwick, bit_higher) - rangeQuery(fenwick, bit_lower - 1);
            cout << count << endl;
        }
    }
    return 0;
}