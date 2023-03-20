#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int arr[101] = {0};
    int start; cin >> start;
    string str;
    while (getline(cin, str)) {
        if (str == "-1") {
            break;
        }
        else {
            stringstream ss(str);
            int parent; ss >> parent;
            int branch;
            while (ss >> branch) {
                arr[branch] = parent;
            }
        }
    }
    int printNext = start;
    while (printNext != 0) {
        cout << printNext << " ";
        printNext = arr[printNext];
    }
    /*for (int i = 0; i < 101; i++) {
        cout << i << ": " << arr[i] << " " << endl;
    }*/
    cout << endl;
    return 0;
}