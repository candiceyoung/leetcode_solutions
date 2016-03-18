class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int left = 0, right = 0;
        int minimum = INT_MAX;
        int sum = 0;
        while (right < size && left <= right) {
            sum += nums[right];
            while (sum >= s) {
                minimum = min(minimum, right - left + 1);
                sum -= nums[left++];
            }
            right++;
        }
        if (minimum == INT_MAX) return 0;
        return minimum;
    }
};