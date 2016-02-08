class Solution {
public:
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &pathSum, int &maximum, int i, int j) {
        if (pathSum[i][j] > 1) return pathSum[i][j];
        vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int result = 1;
        for (int m = 0; m < direction.size(); ++m) {
            int row = i + direction[m].first;
            int col = j + direction[m].second;
            if (row >= 0 && row < matrix.size() && col >= 0 && col <matrix[0].size()) {
                if (matrix[row][col] <= matrix[i][j]) continue;
                result = max(result, dfs(matrix, pathSum, maximum, row, col) + 1);
                
            }
        }
        pathSum[i][j] = result;
        maximum = max(maximum, result);
        return result;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        vector<vector<int>> pathSum(row, vector<int>(col, 1));
        int maximum = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (pathSum[i][j] == 1) dfs(matrix, pathSum, maximum, i, j);
            }
        }
        return maximum;
    }
};