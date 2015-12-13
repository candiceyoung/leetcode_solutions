#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxHere = nums[0];
        int minHere = nums[0];
        int maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                maxHere = max(maxHere * nums[i], nums[i]);
                minHere = min(minHere * nums[i], nums[i]);
            }
            else {
                int temp = maxHere;
                maxHere = max(minHere * nums[i], nums[i]);
                minHere = min(temp * nums[i], nums[i]);
            }
            maxSoFar = max(maxSoFar, maxHere);
        }
        return maxSoFar;
    }
};
int main(void) {
    Solution s;
    vector<int> nums = {5, -2, 3, 1, -1, 4, -6};
    cout << s.maxProduct(nums) << endl;
    return 0;
}
