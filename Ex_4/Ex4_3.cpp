#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int maxSize = 0;
    int startRow = 0, startCol = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                if (dp[i][j] > maxSize) {
                    maxSize = dp[i][j];
                    startRow = i;
                    startCol = j;
                }
            }
        }
    }

    cout << maxSize * maxSize << " " << (startRow - maxSize + 1) << " " << (startCol - maxSize + 1) << endl;

    return 0;
}
