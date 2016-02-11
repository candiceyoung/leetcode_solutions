class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        if (size == 0) return result;
        vector<int> forward, backward;
        forward.push_back(1);
        for (int i = 1; i < size; ++i) {
            forward.push_back(nums[i - 1] * forward[i - 1]);
        }
        backward.push_back(1);
        for (int i = size - 2; i >= 0; --i) {
            backward.push_back(nums[i + 1] * backward[size - 2 - i]);
        }
        for (int i = 0; i < size; ++i) {
            result.push_back(forward[i] * backward[size - 1 - i]);
        }
        return result;
    }
};