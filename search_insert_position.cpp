#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return 0;
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
int main(void) {
    Solution s;
    vector<int> vec = {1, 3, 5, 9};
    cout << s.searchInsert(vec, 5) << endl;
    cout << s.searchInsert(vec, 6) << endl;
    cout << s.searchInsert(vec, 10) << endl;
    vector<int> ivec = {1};
    cout << s.searchInsert(ivec, 0) << endl;
    vector<int> ivec1 = {0};
    cout << s.searchInsert(ivec1, 1) << endl;
    return 0;
}
