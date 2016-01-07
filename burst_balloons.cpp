class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> rangeValues(size + 2, vector<int>(size + 2, 0));
        
        for (int len = 1; len <= size; ++len) {
            for (int start = 1; start <= size - len + 1; ++start) {
                int end = start + len - 1;
                int maximum = 0;
                for (int final = start; final <= end; ++final) {
                    int coins = rangeValues[start][final - 1] + rangeValues[final + 1][end];
                    coins += nums[final] * nums[start - 1] * nums[end + 1];
                    if (coins > maximum) maximum = coins;
                }
                rangeValues[start][end] = maximum;
            }
        }
        return rangeValues[1][size];
    }
};