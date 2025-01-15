#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    vector<long long> dp(n + 1, LLONG_MAX);
    dp[0] = prices[0];

    for (int i = 1; i < n; i++) {
        for (int j = i; i <= (2 * (j + 1)) - 1; j--)
            dp[i] = min(dp[i], (j - 1 >= 0 ? dp[j - 1] : 0) + prices[j]);
    }


    cout << dp[n-1] << endl;
    return 0;
}
