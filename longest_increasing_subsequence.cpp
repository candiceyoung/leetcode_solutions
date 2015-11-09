#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        int maxLength = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};
int main(void) {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> num = {0};
    Solution s;
    cout << s.lengthOfLIS(num) << endl;
    return 0;
}
