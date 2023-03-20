#include <bits/stdc++.h>

using namespace std;

int main() {
    double xa, ya, xb, yb, xc, yc;
    //read in coordinates for vertices
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int n; cin >> n;
    double area = abs(xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb)) / 2;
    cout << fixed << setprecision(1) << area << endl;
    int count = 0;
    double xp, yp;
    for (int i = 0; i < n; i++) {
        //let P = new point. if area of triangle PAB + PAC + PBC  = ABC, then P is inside.
        cin >> xp >> yp;
        double PAB = abs(xa * (yb - yp) + xb * (yp - ya) + xp * (ya - yb)) / 2;
        double PAC = abs(xa * (yp - yc) + xp * (yc - ya) + xc * (ya - yp)) / 2;
        double PBC = abs(xp * (yb - yc) + xb * (yc - yp) + xc * (yp - yb)) / 2;
        if (PAB + PAC + PBC == area) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}