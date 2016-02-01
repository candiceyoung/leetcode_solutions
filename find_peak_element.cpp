#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int possible = nums[0];
        int peak = INT_MIN;
        int n = nums.size();
        int index = 0;
        nums.push_back(INT_MIN);
        for (int i = 1; i <= n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                if (possible > peak) {
                    peak = possible;
                    index = i - 1;
                }
            }
            else {
                possible = nums[i];
            }
        }
        return index;
    }
};
/*
class Solution {
public:
    int helper(vector<int> &A, int start, int end) {
        if (start == end) return end;
        int mid = start + (end - start) / 2;
        int mid1 = mid + 1;
        if (A[mid] < A[mid1]) return helper(A, mid + 1, end);
        else return helper(A, start, mid);
    }
    int findPeakElement(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
*/
int main(void) {
    vector<int> nums = {4, 1, 5, 3};
    Solution s;
    cout << s.findPeakElement(nums) << endl;
    return 0;
}

