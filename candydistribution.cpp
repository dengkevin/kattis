#include <bits/stdc++.h>

using namespace std;

//extended euclids algorithm
//x will be inverse, d returned is gcd
//a * x + b * y = gcd(a, b)
long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    long long t; cin >> t;
    long long k, c;
    for (long long i = 0; i < t; i++) {
        cin >> k >> c;
        //edge cases
        //bag size = 1 and k > 1 kids
        if (c == 1 && k > 1) {
            cout << k + 1 << endl;
            continue;
        }
        //1 kid, bag size = 1
        if ((k == 1) && (c == 1)) {
            cout << 2 << endl;
            continue;
        }
        //1 kid, bag size >= 2 give them big size - 1 candies
        if (k == 1 && c >= 2) {
            cout << 1 << endl;
            continue;
        }
        //handle when k < c 
        long long x, y = 0;
        long long d = gcd(c, k, x, y);
        //x is the solution
        if (x < 0) {
            x += k;
        }
        //if k is a multiple of c
        //x == 0 means not possible for inverse
        if (d != 1 || x == 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << x << endl;
    }
    return 0;
}