#include <bits/stdc++.h>
using namespace std;

long long freCal(int x, int y, int n, int m, int r) {
    int top    = max(0, x - r + 1);
    int bottom = min(x, n - r);
    int left   = max(0, y - r + 1);
    int right  = min(y, m - r);
    return (bottom - top + 1) * (right - left + 1);
}

int main() {
    int n, m, r, k;
    cin >> n >> m >> r >> k;

    long long totalPositions = static_cast<long long>(n - r + 1) * (m - r + 1);
    priority_queue<tuple<long long, int, int>> maxHeap;
    set<pair<int, int>> visited;

    int midX = n / 2, midY = m / 2;
    maxHeap.emplace(freCal(midX, midY, n, m, r), midX, midY);
    visited.emplace(midX, midY);

    const int dis_X[4] = {-1, 1, 0, 0};
    const int dis_Y[4] = {0, 0, -1, 1};
    long long totalFrequency = 0;

    for (int i = 0; i < k && !maxHeap.empty(); ++i) {
        auto [freq, x, y] = maxHeap.top();
        maxHeap.pop();
        totalFrequency += freq;

        for (int j = 0; j < 4; ++j) {
            int nx = x + dis_X[j], ny = y + dis_Y[j];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited.count({nx, ny})) {
                maxHeap.emplace(freCal(nx, ny, n, m, r), nx, ny);
                visited.emplace(nx, ny);
            }
        }
    }

    double result = static_cast<double>(totalFrequency) / totalPositions;
    cout << fixed << setprecision(6) << result << '\n';

    return 0;
}
