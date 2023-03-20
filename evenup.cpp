#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, curr;
    cin >> n;
    deque<int> dq;
    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        dq.push_back(curr);
        if (dq.size() >= 2) {
            curr_sum = *(dq.end() - 2) + *(dq.end() - 1);
            if (curr_sum % 2 == 0) {
                dq.pop_back();
                dq.pop_back();
            }
        }
    }
    cout << dq.size() << endl;
    return 0;
}