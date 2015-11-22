#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, float target) {
        int left = 0; int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = search(nums, target - 0.5) + 1;
        int r = search(nums, target + 0.5);
        cout << l << endl;
        cout << r << endl;
        vector<int> result;
        if (l <= r) {
            result.push_back(l);
            result.push_back(r);
        }
        else {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
};
int main(void) {
    Solution s;
    cout << (-1) / 2 << endl;
    vector<int> nums = {1, 3, 5, 5, 10};
    vector<int> result = s.searchRange(nums, 1);
    cout << result[0] << "  " << result[1] << endl;
    return 0;
}
