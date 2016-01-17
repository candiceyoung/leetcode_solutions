#include <iostream>
#include <vector>
using namespace std;
/* Solution 1: DFS
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
*/
/* Solution 2: union-find */
class Solution {
private:
    int total;
public:
    int find(vector<int> &roots, int index) {
        if (roots[index] == -1) return index;
        else return find(roots, roots[index]);
    }
    void uni(vector<int> &roots, int a, int b) {
        int a_root = find(roots, a);
        int b_root = find(roots, b);
        if (a_root != b_root) {
            roots[b_root] = a_root;
            total--;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size();
        if (row == 0) return count;
        int col = grid[0].size();
        vector<int> roots(row * col, -1);
        total = row * col;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '0') { total--; continue; }
                int index = i * col + j;
                if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                    uni(roots, (i - 1) * col + j, index);
                }
                if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                    uni(roots, i * col + j - 1, index);
                }
            }
        }
        return total;
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
