#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 0; i <= k; i++) dp[i][0] = 0;
    for (int i = 0; i <= n; i++) dp[1][i] = i;

    for (int i = 2; i <= k; i++) {
        int x = 1;
        for (int j = 1; j <= n; j++) {
            while (x < j && dp[i - 1][x - 1] < dp[i][j - x]) {
                x++;
            }
            dp[i][j] = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
        }
    }

    cout << dp[k][n] << endl;
    return 0;
}
