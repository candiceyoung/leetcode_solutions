#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0 || s[0] == '0') return 0;
        vector<int> dp(len + 1, 1);
        for (int i = 1; i < len; ++i) {
            int ones = s[i] - '0';
            int tens = s[i - 1] - '0';
            if (ones == 0) {
                if (tens == 1 || tens == 2) dp[i + 1] = dp[i - 1];
                else return 0;
            }
            else {
                int num = ones + tens * 10;
                if (num >= 11 && num <= 26) {
                    dp[i + 1] = dp[i] + dp[i - 1];
                }
                else dp[i + 1] = dp[i];
            }
        }
        return dp[len];
    }
};
int main(void) {
    string str = "100";
    Solution s;
    cout << s.numDecodings(str) << endl;
    return 0;
}
