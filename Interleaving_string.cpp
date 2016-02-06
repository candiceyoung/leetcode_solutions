class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;
        if (len1 == 0 && len2 == 0 && len3 == 0) return true;
        if (len1 != 0 && len2 == 0 && s1 == s3) return true;
        if (len1 == 0 && len2 != 0 && s2 == s3) return true;
        vector<vector<bool>> dp(1 + len1, vector<bool>(1 + len2, false));
        dp[0][0] = true;
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (i + j - 1 < 0) continue;
                if (i - 1 >= 0 && j - 1 >= 0 && s3[i + j - 1] == s1[i - 1] && s3[i + j - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (i - 1 >= 0 && s3[i + j - 1] == s1[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else if (j - 1 >= 0 && s3[i + j - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[len1][len2];
    }
};