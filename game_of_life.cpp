#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    void check(vector<vector<int>> &board, int row, int col, int m, int n) {
        int total = 0;
        bool dead = false;
        if (board[row][col] == 0) dead = true;
        for (int i = max(0, row - 1); i < min(m, row + 2); ++i) {
            for (int j = max(0, col - 1); j < min(n, col + 2); ++j) {
                if (i == row && j == col) continue;
                if (board[i][j] > 0) total++;
            }
        }
        if (dead == true && total != 0) board[row][col] = -total;
        if (dead == false && total != 0) board[row][col] = total;
        if (total == 0 && dead == true) board[row][col] = INT_MIN / 2;
        if (total == 0 && dead == false) board[row][col] = INT_MAX / 2;

    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) return;
        int m = board.size(); int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                check(board, i, j, m, n);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] > 0) {
                    // alive
                    cout << board[i][j] << endl;
                    if (board[i][j] > 3 || board[i][j] < 2) board[i][j] = 0;
                    else board[i][j] = 1;
                }
                else {
                    // dead
                    cout << "damn it" << board[i][j] << endl;
                    if (board[i][j] == -3) board[i][j] = 1;
                    else board[i][j] = 0;
                }
            }
        }
    }
};
int main(void) {
    return 0;
}
