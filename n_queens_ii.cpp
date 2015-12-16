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
        row_copy = row - 1, col_copy = col + 1;
        while (row_copy >= 0 && col_copy <= temp[0].length() - 1) {
            if (temp[row_copy][col_copy] == 'Q') return false;
            row_copy--; col_copy++;
        }
        return true;
    }
    void recursive(vector<vector<string>> &result, vector<string> &temp, int n, int row) {
        if (row >= n) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (check(temp, row, i)) {
                temp[row][i] = 'Q';
                recursive(result, temp, n, row + 1);
                temp[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> result;
        vector<string> temp(n, string(n, '.'));
        recursive(result, temp, n, 0);
        return result.size();
    }
};
int main(void) {
    Solution s;
    cout << s.totalNQueens(10) << endl;
    return 0;
}
