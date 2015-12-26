#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        vector<int> R(n, 0);
        vector<int> B(n, 0);
        vector<int> G(n, 0);
        R[0] = costs[0][0];
        B[0] = costs[0][1];
        G[0] = costs[0][2];
        for (int i = 1; i < n; ++i) {
            R[i] = min(B[i - 1], G[i - 1]) + costs[i][0];
            B[i] = min(R[i - 1], G[i - 1]) + costs[i][1];
            G[i] = min(R[i - 1], B[i - 1]) + costs[i][2];
        }
        return min(R[n - 1], min(B[n - 1], G[n - 1]));
    }
};
int main(void) {
    Solution s;
    vector<vector<int>> costs = {{1, 2, 3}, {8, 5, 1}, {7, 6, 9}};
    cout << s.minCost(costs) << endl;
    return 0;
}