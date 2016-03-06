class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        int size = nums.size();
        vector<int> result;
        if (size == 0) return result;
        vector<int> forward, backward;
        forward.push_back(1);
        backward.push_back(1);
        for (int i = 1; i < size; ++i) {
            forward.push_back(forward[i - 1] * nums[i - 1]);
        }
        for (int i = 1; i < size; ++i) {
            backward.push_back(backward[i - 1] * nums[size - i]);
        }
        for (int i = 0; i < size; ++i) {
            result.push_back(forward[i] * backward[size - 1 - i]);
        }
        return result;
        */
        int size = nums.size();
        vector<int> result(size, 1);
        int fromBegin = 1, fromEnd = 1;
        for (int i = 0; i < size; ++i) {
            result[i] *= fromBegin;
            fromBegin *= nums[i];
            result[size - 1 - i] *= fromEnd;
            fromEnd *= nums[size - 1 - i];
        }
        return result;
    }
};