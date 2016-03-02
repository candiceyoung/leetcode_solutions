class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        if (len_s == 0 || len_s < len_t) return 0;
        vector<vector<int>> dp(len_s + 1, vector<int>(len_t + 1, 0));
        for (int i = 0; i < len_s + 1; ++i) dp[i][0] = 1;
        for (int i = 1; i < len_s + 1; ++i) {
            for (int j = 1; j < len_t + 1; ++j) {
                if (t[j - 1] != s[i - 1]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp[len_s][len_t];
    }
};