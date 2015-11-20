#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int n = result.size();
            for (int j = 0; j < n; ++j) {
                temp = result[j];
                temp.push_back(nums[i]);
                if (s.find(temp) == s.end()) {
                    result.push_back(temp);
                    s.insert(temp);
                }
            }
        }
        return result;
    }
};
int main(void) {
    vector<int> nums = {1, 2, 2};
    Solution s;
    vector<vector<int>> result = s.subsetsWithDup(nums);
    return 0;
}
