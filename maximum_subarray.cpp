#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArrayRecursive(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        int mid = (start + end) / 2;
        int left = maxSubArrayRecursive(nums, start, mid);
        int right = maxSubArrayRecursive(nums, mid + 1, end);
        int middle = maxSubArrayMiddle(nums, start, end);
        return max(max(left, right), middle);
    }

    int maxSubArrayMiddle(vector<int>& nums, int start, int end) {
        int middle = (start + end) / 2;
        int left_max = nums[middle], right_max = nums[middle];
        int left = nums[middle], right = nums[middle];
        for (int i = middle - 1; i >= 0; --i) {
            left += nums[i];
            if (left_max < left) left_max = left;
        }
        for (int i = middle + 1; i <= end; ++i) {
            right += nums[i];
            if (right_max < right) right_max  = right;
        }
        return left_max + right_max - nums[middle];
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(max(nums[0], nums[1]), nums[0] + nums[1]);
        int mid = (nums.size() - 1) / 2;
        int left = maxSubArrayRecursive(nums, 0, mid);
        int right = maxSubArrayRecursive(nums, mid + 1, nums.size() - 1);
        int middle = maxSubArrayMiddle(nums, 0, nums.size() - 1);
        return max(max(left, right), middle);
    }
};
int main(void) {
    Solution s;
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> ivec = {1, 2};
    cout << s.maxSubArray(ivec) << endl;
    return 0;
}
