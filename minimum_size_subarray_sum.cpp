class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int head = 0;
        int size = nums.size();
        if (size == 0) return 0;
        int minimum = INT_MAX;
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            while (sum >= s) {
                minimum = min(minimum, i - head + 1);
                sum = sum - nums[head];
                head++;
            }
        }
        if (minimum == INT_MAX) return 0;
        else return minimum;
    }
};