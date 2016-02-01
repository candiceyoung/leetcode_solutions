#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int>::iterator it;
        int result = nums[0];
        for (it = nums.end() - 1; it > nums.begin(); --it) {
            if (*it < *(it - 1)) result = *it;
        }
        return result;
    }
};
/*
class Solution {
public:
    int findMin(vector<int> &nums) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};
*/
int main(void) {
    vector<int> vec = {4, 5, 1, 2, 3};
    Solution s;
    cout << s.findMin(vec) << endl;
    return 0;
}
