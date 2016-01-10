class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == candidate || count == 0) {
                candidate = nums[i];
                count++;
            }
            else {
                count--;
            }
        }
        count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == candidate) count++;
        }
        if (count > nums.size() / 2) return candidate;
        else return 0;
    }
};