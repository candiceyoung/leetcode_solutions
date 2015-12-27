class Solution {
public:
    void bfs(vector<vector<int>>& rooms, int row, int col, int distance) {
        if (row < 0 || row >= rooms.size() || col < 0 || col >= rooms[0].size() || rooms[row][col] < distance) return;
        rooms[row][col] = distance;
        bfs(rooms, row - 1, col, distance + 1);
        bfs(rooms, row + 1, col, distance + 1);
        bfs(rooms, row, col - 1, distance + 1);
        bfs(rooms, row, col + 1, distance + 1);
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        if (row == 0) return;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) bfs(rooms, i, j, 0);
            }
        }
    }
};