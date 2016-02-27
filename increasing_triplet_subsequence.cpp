class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) return false;
        int maximum = INT_MAX;
        int minimum = INT_MAX;
        int total = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] < minimum) {
                minimum = nums[i];
            }
            else if (nums[i] > minimum && nums[i] < maximum) {
                maximum = nums[i];
                total = 2;
            }
            else if (nums[i] > maximum) {
                maximum = nums[i];
                total++;
            }
            if (total == 3) return true;
        }
        return false;
    }
};