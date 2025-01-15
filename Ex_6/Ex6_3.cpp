#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &s, int start, int length) {
    if (length > 3 || length == 0) return false;
    if (length > 1 && s[start] == '0') return false;
    int num = stoi(s.substr(start, length));
    return num >= 0 && num <= 255;
}

int countIPAddresses(const string &s) {
    int n = s.size();
    if (n < 4 || n > 12) return 0;

    int count = 0;
    for (int i = 1; i < n && i <= 3; ++i) {
        for (int j = i + 1; j < n && j - i <= 3; ++j) {
            for (int k = j + 1; k < n && k - j <= 3; ++k) {
                if (n - k > 3) continue;
                if (isValid(s, 0, i) && isValid(s, i, j - i) && isValid(s, j, k - j) && isValid(s, k, n - k)) {
                    ++count;
                }
            }
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;
    string  srIP = "";
    for(auto x: s){
        if(x == '\"') continue;
        else
            srIP+=x;
    }
    cout << countIPAddresses(srIP) << endl;
    return 0;
}
