#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, solutions = 0;
vector<int> validRows;

void solve(int row, int cols, int diag1, int diag2) {
    if (row == n) {
        ++solutions;
        return;
    }

    int available = validRows[row] & ~(cols | diag1 | diag2);
    while (available) {
        int pos = available & -available;
        available -= pos;
        solve(row + 1, cols | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1);
    }
}

int main() {
    cin >> n;
    vector<string> board(n);
    validRows.assign(n, (1 << n) - 1);

    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '*') {
                validRows[i] &= ~(1 << j);
            }
        }
    }

    solve(0, 0, 0, 0);
    cout << solutions << endl;
    return 0;
}
