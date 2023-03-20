#include <bits/stdc++.h>

using namespace std;

long long rangeQuery(vector<long long>& fenwick, long long index) {
    long long sum = 0;
    while (index != 0) {
        sum += fenwick[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    //read in n, q
    long long n, q; cin >> n >> q;
    vector<long long> value(7);
    long long v;
    //read in values
    for (long long i = 1; i <= 6; i++) {
        cin >> v;
        value[i] = v;
    }
    string s; cin >> s;
    vector<long long> gemtype(n + 1);
    //6 fenwick trees for each gem type
    vector<vector<long long>> fenwick(7, vector<long long>(n + 1, 0));
    //read in string and store in vector
    for (long long i = 1; i <= n; i++) {
        long long type = s[i - 1] - '0';
        gemtype[i] = type;
        //update fenwick trees from initial string
        long long index = i;
        while (index < n + 1) {
            fenwick[type][index] += 1;
            index += index & -index;
        }
    }
    //q queries
    long long query;
    for (long long i = 0; i < q; i++) {
        cin >> query;
        if (query == 1) {
            //replace kth gem with gem of type p
            long long k, p; cin >> k >> p;
            //subtract occurence of kth gem from fenwick
            long long index = k;
            long long val = gemtype[k];
            while (index < n + 1) {
                fenwick[val][index] -= 1;
                index += index & -index;
            }
            index = k;
            //add occurence of pth gem from fenwick
            while (index < n + 1) {
                fenwick[p][index] += 1;
                index += index & -index;
            }
            //replace kth gem with gem type of p
            gemtype[k] = p;
        }
        else if (query == 2) {
            //change pth value to v
            long long p, v; cin >> p >> v;
            value[p] = v;
        }
        else {
            //print value of gems from l to r inclusive
            long long l, r; cin >> l >> r;
            long long sum = 0;
            //get rqs for each fenwick, multiply by value, then sum together
            for (long long i = 1; i <= 6; i++) {
                sum += value[i] * (rangeQuery(fenwick[i], r) - rangeQuery(fenwick[i], l - 1));
            }
            cout << sum << endl;
        }
    }
    return 0;
}