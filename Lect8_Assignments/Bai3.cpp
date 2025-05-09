#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int n, int X, vector<int>& weight, vector<int>& value) {
    vector<vector<int>> dp(n+1, vector<int>(X+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= X; ++w) {
            if (weight[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight[i-1]] + value[i-1]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][X];
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; ++i)
        cin >> weight[i] >> value[i];

    cout << knapsack(n, X, weight, value) << endl;
    return 0;
}
