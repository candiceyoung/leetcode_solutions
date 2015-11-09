#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int> > pathSum(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 && j == 0) pathSum[i][j] = grid[0][0];
                else if (i == 0) pathSum[i][j] = pathSum[i][j - 1] + grid[i][j];
                else if (j == 0) pathSum[i][j] = pathSum[i - 1][j] + grid[i][j];
                else pathSum[i][j] = min(pathSum[i - 1][j], pathSum[i][j - 1]) + grid[i][j];
            }
        }
        return pathSum[row - 1][col - 1];
    }
};
int main(void) {
    Solution s;
    vector<vector<int> > grid = {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
    cout << s.minPathSum(grid) << endl;
    return 0;
}
