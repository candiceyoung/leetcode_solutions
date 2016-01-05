class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        int total = 0;
        if (size == 0 || amount == 0) return total;
        vector<int> dp(amount + 1, INT_MAX);
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i == coins[j]) dp[i] = 1;
                else if (i > coins[j]) {
                    if (dp[i - coins[j]] != INT_MAX && dp[i - coins[j]] + 1 < dp[i]) dp[i] = dp[i - coins[j]] + 1;
                }
                else break;
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        else return dp[amount];
    }
};