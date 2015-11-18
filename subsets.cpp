#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int n = result.size();
            for (int j = 0; j < n; ++j) {
                temp = result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
int main(void) {
    vector<int> nums = {3, 1, 4, 2};
    Solution s;
    vector<vector<int>> result = s.subsets(nums);
    return 0;
}
