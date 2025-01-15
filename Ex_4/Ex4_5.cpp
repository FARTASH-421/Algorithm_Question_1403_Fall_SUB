#include <bits/stdc++.h>
using namespace std;

int main() {


    int t;
    cin>>t;

    for (int r= 0; r<t; r++) {
        int n;
        long long k;
        cin >> n >> k;
        string word;
        cin >> word;

        vector<char> dp(n);
        long long max_cost = 0;
        char des, src = '$';

        for (int i = 0; i < n; ++i) {
            int cost = word[i] - 'a';
            if (cost <= k) {
                if (cost > max_cost) max_cost = cost;
                dp[i] = 'a';
            } else {
                if (max_cost < k) {
                    int te = k - max_cost;
                    des = word[i];
                    src = char(des - te);
                    k = max_cost;
                    max_cost = max_cost + te;
                }
                if (src <= word[i] && word[i] <= des && src != '$' ) {
                    dp[i] = src;
                } else {
                    dp[i] = word[i];
                }
            }
            cout << dp[i];
        }

        cout << endl;
    }

    return 0;
}
