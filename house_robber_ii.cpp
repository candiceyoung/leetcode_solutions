#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int robS2E(vector<int>& nums, int start, int end) {
        vector<int> value(nums.size(), 0);
        value[start] = nums[start];
        value[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            value[i] = max(value[i - 1], value[i - 2] + nums[i]);
        }
        return value[end];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return max(robS2E(nums, 0, n - 2), robS2E(nums, 1, n - 1));
    }
};
int main(void) {
    vector<int> nums = {1, 2, 9, 8, 2};
    vector<int> nums1 = {1, 3, 1, 3, 100};
    Solution s;
    cout << s.rob(nums1) << endl;
    return 0;
}
