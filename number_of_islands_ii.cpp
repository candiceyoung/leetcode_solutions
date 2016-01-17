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
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        total = 0;
        vector<int> roots(m * n, -1);
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<int> result;
        for (int i = 0; i < positions.size(); ++i) {
            int row = positions[i].first;
            int col = positions[i].second;
            grid[row][col] = 1;
            total++;
            int index = row * n + col;
            if (row - 1 >= 0 && grid[row - 1][col] == 1) uni(roots, (row - 1) * n + col, index);
            if (col - 1 >= 0 && grid[row][col - 1] == 1) uni(roots, row * n + col - 1, index);
            if (row + 1 < m && grid[row + 1][col] == 1) uni(roots, (row + 1) * n + col, index);
            if (col + 1 < n && grid[row][col + 1] == 1) uni(roots, row * n + col + 1, index);
            result.push_back(total);
        }
        return result;
    }
};