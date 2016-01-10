class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1, candidate2;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == candidate1 || count1 == 0) {
                candidate1 = nums[i];
                count1++;
            }
            else if (nums[i] == candidate2 || count2 == 0) {
                candidate2 = nums[i];
                count2++;
            }
            else if (nums[i] != candidate1 || nums[i] != candidate2) {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == candidate1) count1++;
            else if (nums[i] == candidate2) count2++;
        }
        vector<int> result;
        if (count1 > nums.size() / 3) result.push_back(candidate1);
        if (count2 > nums.size() / 3) result.push_back(candidate2);
        return result;
    }
};