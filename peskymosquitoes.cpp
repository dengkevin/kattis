#include <bits/stdc++.h>

using namespace std;

double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

int main() {
    int n; cin >> n;
    int m;
    double d;
    for (int i = 0; i < n; i++) {
        cin >> m >> d;
        //1 mosquito case
        if (m == 1) {
            cout << 1 << endl;
            continue;
        }
        double r = d / 2;
        vector<pair<double, double>> coordinates;
        for (int j = 0; j < m; j++) {
            pair<double, double> p;
            cin >> p.first;
            cin >> p.second;
            coordinates.push_back(p);
        }
        int max_count_global = 0;
        //loop through all coordinates n^2
        bool close_enough = false;
        for (int j = 0; j < coordinates.size() - 1; j++) {
            for (int k = j + 1; k < coordinates.size(); k++) {
                //if distance is at most diameter, we can fit 2 circles with the two points
                if (distance(coordinates[j], coordinates[k]) <= d) {
                    close_enough = true;
                    //referring to diagram for computing centers of 2 respective circles
                    //x_1, y_1 are coordinates for j
                    double x_1 = coordinates[j].first;
                    double y_1 = coordinates[j].second;
                    //x_2, y_2 are coordinates for k
                    double x_2 = coordinates[k].first;
                    double y_2 = coordinates[k].second;
                    //calc opposite length (with regards to hypotenuse being distance to midpoint of j and k)
                    double x_a = 0.5 * (x_2 - x_1);
                    double y_a = 0.5 * (y_2 - y_1);
                    //center at x_0, y_0
                    double x_0 = x_1 + x_a;
                    double y_0 = y_1 + y_a;
                    //a is the length from point to midpoint
                    double a = sqrt(pow(x_a, 2) + pow(y_a, 2));
                    //b is the length from midpoint to center
                    double b = sqrt(pow(r, 2) - pow(a, 2));

                    //x_3, y_3 is center for 1 circle
                    double x_3 = x_0 + ((b * y_a) / a);
                    double y_3 = y_0 - ((b * x_a) / a);
                    pair<double, double> center_1;
                    center_1.first = x_3;
                    center_1.second = y_3;
                    //x_4, y_4 is center for the other circle
                    double x_4 = x_0 - (b * y_a) / a;
                    double y_4 = y_0 + (b * x_a) / a;
                    pair<double, double> center_2;
                    center_2.first = x_4;
                    center_2.second = y_4;
                    //find max number of points both circles can fit
                    int count1 = 0;
                    int count2 = 0;
                    for (auto u : coordinates) {
                        if (distance(center_1, u) <= r) {
                            count1++;
                        }
                        if (distance(center_2, u) <= r) {
                            count2++;
                        }
                    }
                    int max_count_here = max(count1, count2);
                    max_count_global = max(max_count_global, max_count_here);
                }
            }
        }
        //handles super spread out mosquitoes
        if (!close_enough) {
            cout << 1 << endl;
        }
        else {
            cout << max_count_global << endl;
        }
    }
    return 0;
}