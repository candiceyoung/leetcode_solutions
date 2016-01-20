class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) return false;
        int col = board[0].size();
        for (int i = 0; i < row; ++i) {
            set<int> st;
            int count = 0;
            for (int j = 0; j < col; ++j) {
                if (board[i][j] != '.') st.insert(board[i][j]);
                else count++;
            }
            if (st.size() + count != 9) return false;
        }
        for (int i = 0; i < col; ++i) {
            set<int> st;
            int count = 0;
            for (int j = 0; j < row; ++j) {
                if (board[j][i] != '.') st.insert(board[j][i]);
                else count++;
            }
            if (st.size() + count != 9) return false;
        }
        for (int i = 0; i < row; i = i + 3) {
            for (int j = 0; j < col; j = j + 3) {
                set<int> st;
                int count = 0;
                for (int m = i; m < i + 3; ++m) {
                    for (int n = j; n < j + 3; ++n) {
                        if (board[m][n] != '.') st.insert(board[m][n]);
                        else count++;
                    }
                }
                if (st.size() + count != 9) return false;
            }
        }
        return true;
    }
};