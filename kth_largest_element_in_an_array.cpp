#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) 
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[r], nums[left]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};
int main(void) {
    vector<int> nums = {3, 5, 6, 2, 1, 4};
    vector<int> nums1 = {2, 1};
    Solution s;
    cout << s.findKthLargest(nums1, 2) << endl;
    return 0;
}
