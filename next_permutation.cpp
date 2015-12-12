#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int pos = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) pos = i - 1;
        }
        for (int i = pos + 1; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        if (pos == -1) return;
        for (int i = pos + 1; i < nums.size(); ++i) {
            if (nums[pos] < nums[i]) {
                swap(nums[pos], nums[i]);
                break;
            }
        }
    }
};
int main(void) {
    vector<int> nums = {1, 2, 5, 9, 6, 5, 3, 1};
    vector<int> nums1 = {3, 2, 1};
    Solution s;
    s.nextPermutation(nums1);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << "    ";
    }
    cout << endl;
    return 0;
}
