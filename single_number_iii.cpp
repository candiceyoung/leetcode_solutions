class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int size = nums.size();
        if (size == 0) return result;
        int diff = 0;
        for (int i = 0; i < size; ++i) diff ^= nums[i];
        diff = diff & (-diff);
        for (int i = 0; i < size; ++i) {
            if (diff & nums[i]) result[0] ^= nums[i];
            else result[1] ^= nums[i];
        }
        return result;
    }
};