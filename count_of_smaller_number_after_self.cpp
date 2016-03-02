class Solution {
public:
    int findIndex(vector<int>& sorted, int target) {
        int size = sorted.size();
        if (size == 0) return 0;
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sorted[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        if (size == 0) return result;
        result.resize(size, 0);
        vector<int> sorted;
        sorted.push_back(nums[size - 1]);
        for (int i = size - 2; i >= 0; --i) {
            int index = findIndex(sorted, nums[i]);
            sorted.insert(sorted.begin() + index, nums[i]);
            result[i] = index;
        }
        return result;
    }
};