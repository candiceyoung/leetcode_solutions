class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char val) {
        int r = row - row % 3;
        int c = col - col % 3;
        for (int i = 0; i < 9; ++i) if (board[i][col] == val) return false;
        for (int i = 0; i < 9; ++i) if (board[row][i] == val) return false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[r + i][c + j] == val) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return helper(board, row + 1, 0);
        if (board[row][col] != '.') return helper(board, row, col + 1);
        for (int i = 0; i < 9; ++i) {
            char temp = '1' + i;
            if (check(board, row, col, temp)) {
                board[row][col] = temp;
                if (helper(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row = board.size();
        if (row != 9) return;
        int col = board[0].size();
        if (col != 9) return;
        helper(board, 0, 0);
    }
};