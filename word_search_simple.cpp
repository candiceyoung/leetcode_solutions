#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col, string &word, int start) {
        if (start == word.size()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size()) return false;
        char temp = board[row][col];
        if (temp == word[start]) {
            board[row][col] = '@';
            if (dfs(board, row - 1, col, word, start + 1)) return true;
            if (dfs(board, row, col + 1, word, start + 1)) return true;
            if (dfs(board, row + 1, col, word, start + 1)) return true;
            if (dfs(board, row, col - 1, word, start + 1)) return true;
            board[row][col] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
int main(void) {
	Solution s;
	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
    vector<vector<char>> board1 = {
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'}
    };
    vector<vector<char>> board2 = {
        {'A', 'A'}
    };
	string word = "AA";
	cout << s.exist(board2, word) << endl;
	return 0;
}
