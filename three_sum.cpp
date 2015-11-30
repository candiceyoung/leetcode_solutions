#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2) return result;
        int i = 0;
        int outer_pre = nums[0];
        while (i < nums.size() - 2) {
            if (i != 0 && nums[i] == outer_pre) {i++; continue;}
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            int target = 0 - nums[i];
            int inner_pre_head = nums[p1];
            int inner_pre_tail = nums[p2];
            while (p1 < p2) {
                if (p1 != (i + 1) && nums[p1] == inner_pre_head) {
                    p1++;
                    continue;
                }
                if (p2 != nums.size() - 1 && nums[p2] == inner_pre_tail) {
                    p2--;
                    continue;
                }
                if (nums[p1] + nums[p2] < target) {
                    inner_pre_head = nums[p1++];
                }
                else if (nums[p1] + nums[p2] > target) {
                    inner_pre_tail = nums[p2--];
                }
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[p1]);
                    temp.push_back(nums[p2]);
                    result.push_back(temp);
                    inner_pre_head = nums[p1++];
                    inner_pre_tail = nums[p2--];
                }
            }
            outer_pre = nums[i++];
        }
        return result;
    }
};
int main(void) {
    Solution s;
    vector<int> nums = {1, 2, 4, -3};
    vector<int> nums1 = {2,5,5,8,-7,-9,5,-1,-4,2,8,4,-6,-2,-2,9,-2,13,1,0,9,9,4,-13,13,3,-14,11,-5,-13,3,4,7,-15,-11,7,13,1,13,-14,11,-1,5,-10,12,11,14,-13,1,-8,3,-4,-14,14,-10,-15,-6,-9,3,-4,-7,-8,-15,8,-8,12,-8,13,-2,-9,14,-6,5,-3,-9,-6,-7,-10,-3,9,-2,7,-10,-9,-2,-5,13,7,-6,2,-12,-6,1,10,9,0,7,-13,-2,-9,-7,-2,-8,5,10,-1,6,-12,4,10,12,9,2,10,8,-15,12,6,-1,-9,-7,2};
    cout << nums1.size() << endl;
    vector<vector<int>> result = s.threeSum(nums1);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
