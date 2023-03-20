#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    //make a copy of n to reference later
    int n_copy = n;
    int product = 1;
    //we will omit first smallest prime factor
    bool first = true;
    //reduce to odd
    while (n % 2 == 0) {
        if (first) {
            n = n / 2;
            first = false;
            continue;
        }
        product *= 2;
        n /= 2;
    }
    //prime factor 3 to sqrt(n) ignoring evens
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        //prime factor
        while (n % i == 0) {
            if (first) {
                n = n / i;
                first = false;
                continue;
            }
            product *= i;
            n /= i;
        }
    }
    //if remainder is prime
    if (n > 2 && !first) {
        product *= n;
    }
    //result is n - product
    cout << n_copy - product << endl;
    return 0;
}