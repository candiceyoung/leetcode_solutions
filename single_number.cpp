class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int result = nums[0];
        for (int i = 1; i < size; ++i) result ^= nums[i];
        return result;
    }
};