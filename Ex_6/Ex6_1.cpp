#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMovesToPaint(vector<int>& walls, int left, int right, int baseHeight) {
    if (left > right) return 0;

    int minHeight = *min_element(walls.begin() + left, walls.begin() + right + 1);
    int moves = minHeight - baseHeight;

    int last = left;
    for (int i = left; i <= right; ++i) {
        if (walls[i] == minHeight) {
            moves += minMovesToPaint(walls, last, i - 1, minHeight);
            last = i + 1;
        }
    }
    moves += minMovesToPaint(walls, last, right, minHeight);
    return min(moves, right - left + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> walls(n);
    for (int i = 0; i < n; ++i) {
        cin >> walls[i];
    }
    cout << minMovesToPaint(walls, 0, n - 1, 0) << endl;
    return 0;
}
