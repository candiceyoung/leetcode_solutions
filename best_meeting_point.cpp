class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> row, col;
        if (grid.size() == 0) return 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());
        int mid_row, mid_col;
        int row_size = row.size();
        int col_size = col.size();
        if (row_size % 2 == 0) {
            mid_row = (row[row_size / 2 - 1] + row[row_size / 2]) / 2;
        }
        else {
            mid_row = row[row_size / 2];
        }
        if (col_size % 2 == 0) {
            mid_col = (col[col_size / 2 - 1] + col[col_size / 2]) / 2;
        }
        else {
            mid_col = col[col_size / 2];
        }
        int distance = 0;
        for (int i = 0; i < row_size; ++i) {
            distance += abs(row[i] - mid_row);
        }
        for (int j = 0; j < col_size; ++j) {
            distance += abs(col[j] - mid_col);
        }
        return distance;
    }
};