class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int size = nums.size();
        if (size == 0) {
            string temp = (lower == upper) ? to_string(lower) : to_string(lower) + "->" + to_string(upper);
            result.push_back(temp);
            return result;
        }
        int start = lower, end;
        for (int i = 0; i < size; ++i) {
            if (start == nums[i]) start++;
            else if (start < nums[i]) {
                end = nums[i] - 1;
                string temp = (start == end) ? to_string(start) : to_string(start) + "->" + to_string(end);
                result.push_back(temp);
                start = nums[i] + 1;
            }
        }
        if (start < upper) {
            string temp = to_string(start) + "->" + to_string(upper);
            result.push_back(temp);
        }
        if (start == upper) {
            result.push_back(to_string(start));
        }
        return result;
    }
};