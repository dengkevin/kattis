#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, price; cin >> n;
    vector<int> cost(n);
    //read in costs
    for (int i = 0; i < n; i++) {
        cin >> price;
        cost[i] = price;
    }
    //At dp[i], denotes a value >= 1 if there is exactly 1 way to make i, -1 if no way to make i yet, or 0 if ambiguous
    //if dp[i] >= 1, the dp[i] value represents the last order which made it that cost value.
    //dp array is max 31000 since it is order total max = 30k plus price of 1 thing max = 1k.
    vector<int> dp(31001);
    fill(dp.begin(), dp.end(), -1);
    //base case
    dp[0] = 1;
    //knapsack unbounded
    //for each cost, calculate what can be made
    for (int i = 0; i < cost.size(); i++) {
        int cost_at_i = cost[i];
        //go through each possible value. dp[cost_at_i + cost_at_j] can be made if cost_at_j can be made
        for (int j = 0; j < 30001; j++) {
            int can_make_j = dp[j];
            if (can_make_j >= 1) {
                //if we can make j, we can make (i + j)th value GIVEN that we can't make the (i + j)th value before
                if (dp[j + cost_at_i] == -1) {
                    dp[j + cost_at_i] = i + 1;
                }
                //if we can already make (i + j)th value before, then it is ambigious
                else {
                    dp[j + cost_at_i] = 0;
                }
            }
            //if dp[j] is ambiguous, make dp[j + cost_at_i] ambiguous
            if (can_make_j == 0) {
                dp[j + cost_at_i] = 0;
            }
        }
    }
    //backtracking
    //read in order data
    int m; cin >> m;
    int eval;
    //for all orders
    for (int i = 0; i < m; i++) {
        cin >> eval;
        //if dp[order] is -1, then we know it is impossible to make that order
        if (dp[eval] == -1) {
            cout << "Impossible" << endl;
        }
        //if dp[order] is 0, then we know that order is ambiguous
        else if (dp[eval] == 0) {
            cout << "Ambiguous" << endl;
        }
        //if not impossible nor ambiguous, we can run backtracking on knapsack unbounded
        else {
            //order vector represents the reverse order in which the orders were placed
            vector<int> order;
            int index = 0;
            //while the price evaluated is still above 0 (given that there is only 1 way to make it, when eval = 0 that is when the algorithm should stop)
            while (eval > 0) {
                //get the last item cost bought that made the cost var eval
                index = dp[eval];
                //append to order vector
                order.push_back(index);
                //subtract from the total price the last cost it took to get there
                eval -= cost[index - 1];
            }
            //since order stores it in reverse order (because of backtracking) we simply reverse print to get the order
            for (int i = order.size() - 1; i >= 0; i--) {
                cout << order[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}