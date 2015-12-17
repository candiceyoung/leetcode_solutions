#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int low = 0; int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == nums[mid]) return true;
            if (nums[mid] > nums[high]) {
                if (nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else if (nums[high] > nums[mid]) {
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
            else {
                high--;
            }
        }
        return false;
    }
};
int main(void) {
    vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3, 4};
    Solution s;
    cout << s.search(nums, 4) << endl;
    return 0;
}
