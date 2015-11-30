#include <iostream>
#include <vector>
#include <climits>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2) return 0;
        int i = 0;
        int outer_pre = nums[0];
        int closest_distance = 0;
        while (i < nums.size() - 2) {
            if (i != 0 && nums[i] == outer_pre) {i++; continue;}
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            int inner_pre_head = nums[p1];
            int inner_pre_tail = nums[p2];
            if (i == 0) closest_distance = nums[i] + nums[p1] + nums[p2];
            while (p1 < p2) {
                if (p1 != (i + 1) && nums[p1] == inner_pre_head) {
                    p1++;
                    continue;
                }
                if (p2 != nums.size() - 1 && nums[p2] == inner_pre_tail) {
                    p2--;
                    continue;
                }
                int temp = nums[p1] + nums[p2] + nums[i];
                if (abs(temp - target) < abs(closest_distance - target)) closest_distance = temp;
                if (temp < target) {
                    inner_pre_head = nums[p1++];
                }
                else if (temp > target) {
                    inner_pre_tail = nums[p2--];
                }
                else {
                    closest_distance = target;
                    return closest_distance;
                }
            }
            outer_pre = nums[i++];
        }
        return closest_distance;
    }
};
int main(void) {
    Solution s;
    vector<int> nums = {-1, 2, 1, -4};
    vector<int> nums1 = {-3, -2, -5, 3, -4};
    cout << s.threeSumClosest(nums1, -1) << endl;
    return 0;
}
