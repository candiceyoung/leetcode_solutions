class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int size = nums.size();
        if (size == 0) return result;
        int start = nums[0], end = start;
        for (int i = 1; i < size; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                end = nums[i];
            }
            else {
                end = nums[i - 1];
                string temp;
                if (start != end) temp = to_string(start) + "->" + to_string(end);
                else temp = to_string(start);
                result.push_back(temp);
                start = nums[i];
                end = nums[i];
            }
        }
        if (start != end) result.push_back(to_string(start) + "->" + to_string(end));
        else result.push_back(to_string(start));
        return result;
    }
};