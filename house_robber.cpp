#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> value;
        value.push_back(nums[0]);
        value.push_back(max(nums[0], nums[1]));
        for (int i = 2; i < nums.size(); ++i) {
            value.push_back(max(value[i - 1], value[i - 2] + nums[i]));
        }
        return value[nums.size() - 1];
    }
};
int main(void) {
    vector<int> nums = {5, 8, 1, 3, 6};
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}
