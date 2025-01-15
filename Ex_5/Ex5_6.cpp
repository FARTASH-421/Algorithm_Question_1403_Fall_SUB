#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, maxFee;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    int from, to, fee;
    for (int i = 0; i < m; ++i) {
        cin >> from >> to >> fee;
        dist[from][to] = min(dist[from][to], fee);
        dist[to][from] = min(dist[to][from], fee);
    }

    cin >> maxFee;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int myMin = n + 1;
    int bestNode = -1;

    for (int i = 0; i < n; ++i) {
        int reachable = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= maxFee) {
                ++reachable;
            }
        }
        if (reachable < myMin || (reachable == myMin && i > bestNode)) {
            myMin = reachable;
            bestNode = i;
        }
    }

    cout << bestNode << endl;

    return 0;
}
