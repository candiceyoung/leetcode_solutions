#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            auto search = m.find(target - x);
            if (search != m.end()) {
                result.push_back(search->second + 1);
                result.push_back(i + 1);
            }
            m[nums[i]] = i;
        }
        return result;
    }
};
int main(void) {
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    vector<int> result = s.twoSum(nums, 9);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
