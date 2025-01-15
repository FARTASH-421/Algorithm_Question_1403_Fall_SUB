#include <bits/stdc++.h>
using namespace std;


int main() {
    string matrix_input;
    getline(cin, matrix_input);

    vector<vector<int>> matrix;
    matrix_input = matrix_input.substr(1, matrix_input.size() - 2);

    stringstream ss(matrix_input);
    string row_str;
    while (getline(ss, row_str, ']')) {
        if (row_str.find('[') != string::npos) {
            row_str = row_str.substr(row_str.find('[') + 1);
            stringstream row_ss(row_str);
            int num;
            char delim;
            vector<int> row;
            while (row_ss >> num) {
                row.push_back(num);
                row_ss >> delim;
            }
            matrix.push_back(row);
        }
    }

    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> mydp(row, vector<int>(col, 0));

    mydp[0][0] = matrix[0][0];
    for (int i = 1; i < col; ++i) mydp[0][i] = mydp[0][i - 1] + matrix[0][i];
    for (int i = 1; i < row; ++i) mydp[i][0] = mydp[i - 1][0] + matrix[i][0];


    for (int i = 1; i < row; ++i)
        for (int j = 1; j < col; ++j) mydp[i][j] = min(mydp[i - 1][j], mydp[i][j - 1]) + matrix[i][j];


    cout << mydp[row - 1][col - 1] << endl;

    return 0;
}