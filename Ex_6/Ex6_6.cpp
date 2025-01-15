#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        unordered_map<int, int> prefix_sum_map;
        int prefix_sum = 0, count = 0;

        for (int i = 0; i < n; i++) {
            prefix_sum += arr[i];
            if (prefix_sum == 0) {
                count++;
                prefix_sum = 0;
                prefix_sum_map.clear();
            } else if (prefix_sum_map.find(prefix_sum) != prefix_sum_map.end()) {
                count++;
                prefix_sum = 0;
                prefix_sum_map.clear();
            } else {
                prefix_sum_map[prefix_sum] = i;
            }
        }

        cout << count << endl;
    }

    return 0;
}
