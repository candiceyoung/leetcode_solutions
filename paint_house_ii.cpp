class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        vector<vector<int>> M(n, vector<int>(k, 0));
        vector<int> minimum(n, INT_MAX);
        vector<int> color(n, 0);
        vector<int> second_minimum(n, INT_MAX);
        for (int i = 0; i < k; ++i) {
            M[0][i] = costs[0][i];
            if (M[0][i] >= minimum[0]) {
                second_minimum[0] = min(second_minimum[0], M[0][i]);
            }
            else {
                second_minimum[0] = minimum[0];
                minimum[0] = M[0][i];
                color[0] = i;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (color[i - 1] == j) {
                    M[i][j] = second_minimum[i - 1] + costs[i][j];
                }
                else {
                    M[i][j] = minimum[i - 1] + costs[i][j];
                }
                if (minimum[i] <= M[i][j]) {
                    second_minimum[i] = min(second_minimum[i], M[i][j]);
                }
                else {
                    second_minimum[i] = minimum[i];
                    minimum[i] = M[i][j];
                    color[i] = j;
                }
            }
        }
        return minimum[n - 1];
    }
};