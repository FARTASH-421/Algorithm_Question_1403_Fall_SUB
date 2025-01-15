#include <bits/stdc++.h>
using namespace std;
const long long INF = 10000000000000000LL;

int main() {
    int n;
    cin >> n;
    vector<long long> myCost(n);
    for (int i = 0; i < n; ++i) cin >> myCost[i];

    vector<string> myWords(n);
    for (int i = 0; i < n; ++i) cin >> myWords[i];

    vector<long long > dpNorm(n, INF);
    vector<long long > dpRever(n, INF);

    dpNorm[0] = 0;
    dpRever[0] = myCost[0];

    for (int i = 1; i < n; ++i) {

        string revPrev = myWords[i - 1];
        reverse(revPrev.begin(), revPrev.end());
        string revCurr = myWords[i];
        reverse(revCurr.begin(), revCurr.end());

        if (myWords[i] >= myWords[i - 1])
            dpNorm[i] = min(dpNorm[i], dpNorm[i - 1]);
        if (myWords[i] >= revPrev)
            dpNorm[i] = min(dpNorm[i], dpRever[i - 1]);

        if (revCurr >= myWords[i - 1])
            dpRever[i] = min(dpRever[i],  dpNorm[i - 1] + myCost[i]);
        if (revCurr >= revPrev)
            dpRever[i] = min(dpRever[i], dpRever[i - 1] + myCost[i]);

    }

    long long result = min(dpNorm[n-1], dpRever[n - 1]);
    cout << (result >= INF ? -1 : result) << endl;

    return 0;
}
