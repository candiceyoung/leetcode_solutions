#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int size = nums.size();
        if (size == 0 || size == 1 || size == 2) return 0;
        int i = 0;
        while (i < nums.size() - 2) {
            int p1 = i+1, p2 = size - 1;
            int t = target - nums[i];
            while (p1 < p2) {
                if (nums[p1] + nums[p2] < t) {
                    count = count + p2 - p1;
                    p1++;
                }
                else {
                    p2--;
                }
            }
            i++;
        }
        return count;
    }
};
int main(void) {
    Solution s;
    vector<int> nums = {-2, -2, 0, 1, 3};
    cout << s.threeSumSmaller(nums, 2) << endl;
    return 0;
}