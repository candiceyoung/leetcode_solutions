#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int col = triangle.size();
        vector<vector<int>> dp(col, vector<int>(col, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < col; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }
                else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }
        int min = dp[col - 1][0];
        for (int i = 1; i < col; ++i) {
            if (dp[col - 1][i] < min) min = dp[col - 1][i];
        }
        return min;
    }
};
int main(void) {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}
