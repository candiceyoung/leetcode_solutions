#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col >= grid[row].size() || col < 0) return false;
        if (grid[row][col] == '1') {
            grid[row][col] = '0';
            dfs(grid, row - 1, col);
            dfs(grid, row, col + 1);
            dfs(grid, row + 1, col);
            dfs(grid, row, col - 1);
            return true;
        }
        return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        if (grid.size() == 0) return false;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (dfs(grid, i, j)) num++; 
            }
        }
        return num;
    }
};
int main(void) {
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << s.numIslands(grid) << endl;
    return 0;
}
