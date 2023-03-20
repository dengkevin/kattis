#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int curr;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        if (curr <= d) {
            cout << "It hadn't snowed this early in " << i << " years!" << endl;
            return 0;
        }
    }
    cout << "It had never snowed this early!" << endl;
    return 0;
}