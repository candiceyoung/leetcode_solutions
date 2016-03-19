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

/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> positive(size);
        vector<int> negative(size);
        int maximum = nums[0];
        positive[0] = nums[0];
        negative[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            if (nums[i] > 0) {
                positive[i] = (positive[i - 1] > 0) ? positive[i - 1] * nums[i] : nums[i];
                negative[i] = (negative[i - 1] < 0) ? negative[i - 1] * nums[i] : nums[i];
            }
            else if (nums[i] < 0) {
                positive[i] = (negative[i - 1] < 0) ? negative[i - 1] * nums[i] : nums[i];
                negative[i] = (positive[i - 1] > 0) ? positive[i - 1] * nums[i] : nums[i];
            }
            else {
                positive[i] = 0;
                negative[i] = 0;
            }
            maximum = max(maximum, positive[i]);
        }
        return maximum;
    }
};
*/
