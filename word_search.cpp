#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool dfs(vector<vector<char>>& board, int row, int col, string &word, int start, vector<vector<int>>& visited) {
        cout << "row: " << row << "col: " << col << endl;
		if (word[start] != board[row][col]) return false;
		if (start == word.size() - 1) return true;
		if (row > 0) {
            cout << "try upward" << endl;
			visited[row - 1][col]  = 1;
			if (dfs(board, row - 1, col, word, start + 1, visited) == true) return true;
			visited[row - 1][col] = 0;
		}
		if (col < board[0].size() - 1) {
            cout << "try right" << endl;
			visited[row][col + 1] = 1;
			if (dfs(board, row, col + 1, word, start + 1, visited) == true) return true;
			visited[row][col + 1] = 0;
		}
		if (row < board.size() - 1) {
            cout << "try downward" << endl;
			visited[row + 1][col] = 1;
			if (dfs(board, row + 1, col, word, start + 1, visited) == true) return true;
			visited[row + 1][col] = 0;
		}
		if (col > 0) {
            cout << "try left" << endl;
			visited[row][col - 1] = 1;
			if(dfs(board, row, col - 1, word, start + 1, visited) == true) return true;
			visited[row - 1][col] = 0;
		}
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, i, j, word, 0, visited) == true) return true;
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
	string word = "SEE";
	cout << s.exist(board, word) << endl;
	return 0;
}
