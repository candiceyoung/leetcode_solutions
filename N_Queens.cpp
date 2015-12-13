#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool check(vector<string> &temp, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (temp[i][col] == 'Q') return false;
        }
        int row_copy = row - 1, col_copy = col - 1;
        while (row_copy >= 0 && col_copy >= 0) {
            if (temp[row_copy][col_copy] == 'Q') return false;
            row_copy--; col_copy--;
        }
        int row_copy1 = row - 1, col_copy1 = col + 1;
        while (row_copy1 >= 0 && col_copy1 < temp[0].length()) {
            if (temp[row_copy1][col_copy1] == 'Q') return false;
            row_copy1--; col_copy1++;
        }
        return true;
    }
    void recursive(int n, vector<vector<string>> &result, int row, vector<string> &temp) {
        if (row >= n) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (check(temp, row, i) == true) {
                temp[row][i] = 'Q';
                recursive(n, result, row+1, temp);
                temp[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> temp(n, string(n, '.'));
        recursive(n, result, 0, temp);
        return result;
    }
};
int main(void) {
    Solution s;
    vector<vector<string>> result = s.solveNQueens(4);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << endl;
        }
    }
    return 0;
}
