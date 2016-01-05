class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int size = nums.size();
        int maximum = INT_MIN;
        int sum = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            if (sum == k) maximum = max(maximum, i + 1);
            else if (m.find(sum - k) != m.end()) maximum = max(maximum, i - m[sum - k]);
            if (m.find(sum) == m.end()) m[sum] = i;
        }
        if (maximum == INT_MIN) return 0;
        else return maximum;
    }
};