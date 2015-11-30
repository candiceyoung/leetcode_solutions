#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2) return result;
        int i = 0;
        int outer_pre = nums[0];
        while (i < nums.size() - 3) {
            if (i != 0 && nums[i] == outer_pre) {i++; continue;}
            int j = i + 1;
            int mid_pre = nums[j];
            while (j < nums.size() - 2) {
                if (j != (i + 1) && nums[j] == mid_pre) {j++; continue;}
                int p1 = j + 1;
                int p2 = nums.size() - 1;
                int inner_pre_head = nums[p1];
                int inner_pre_tail = nums[p2];
                while (p1 < p2) {
                    int temp_sum = nums[i] + nums[j] + nums[p1] + nums[p2];
                    if (p1 != (j + 1) && nums[p1] == inner_pre_head) {p1++; continue;}
                    if (p2 != (nums.size() - 1) && nums[p2] == inner_pre_tail) {p2--; continue;}
                    if (temp_sum < target) inner_pre_head = nums[p1++];
                    else if (temp_sum > target) inner_pre_tail = nums[p2--];
                    else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[p1]);
                        temp.push_back(nums[p2]);
                        result.push_back(temp);
                        inner_pre_head = nums[p1++];
                        inner_pre_tail = nums[p2--];
                    }
                }
                mid_pre = nums[j++];
            }
            outer_pre = nums[i++];
        }
        return result;
    }
};
int main(void) {
    Solution s;
    vector<vector<int>> result;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    result = s.fourSum(nums, 0);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
