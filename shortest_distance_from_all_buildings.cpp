class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return -1;
        int col = grid[0].size();
        
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        vector<vector<int>> reach(row, vector<int>(col, 0));
        int building = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    queue<pair<int, int>> q;
                    int dist = 0;
                    building++;
                    for (int k = 0; k < 4; ++k) {
                        int r = i + directions[k].first;
                        int c = j + directions[k].second;
                        if (r >= 0 && r < row && c >= 0 && c < col && grid[r][c] == 0) {
                            distance[r][c] = (distance[r][c] == INT_MAX) ? dist + 1 : dist + 1 + distance[r][c];
                            reach[r][c]++;
                            q.push(make_pair(r, c));
                            visited[r][c] = true;
                        }
                    }
                    dist++;
                    while (!q.empty()) {
                        int queueSize = q.size();
                        for (int k = 0; k < queueSize; ++k) {
                            pair<int, int> temp = q.front();
                            q.pop();
                            int current_row = temp.first;
                            int current_col = temp.second;
                            for (int k = 0; k < 4; ++k) {
                                int next_row = current_row + directions[k].first;
                                int next_col = current_col + directions[k].second;
                                if (next_row >= 0 && next_row < row && next_col >= 0 && next_col < col && grid[next_row][next_col] == 0 && !visited[next_row][next_col]) {
                                    reach[next_row][next_col]++;
                                    visited[next_row][next_col] = true;
                                    distance[next_row][next_col] = (distance[next_row][next_col] == INT_MAX) ? dist + 1 : dist + distance[next_row][next_col] + 1;
                                    q.push(make_pair(next_row, next_col));
                                }
                            }
                        }
                        dist++;
                    }
                }
                
            }
        }
        int minimum = INT_MAX;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0 && reach[i][j] == building) {
                    minimum = min(minimum, distance[i][j]);
                }
            }
        }
        return (minimum == INT_MAX) ? -1 : minimum;
    }
};