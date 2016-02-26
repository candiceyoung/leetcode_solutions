class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return false;
        set<int> st;
        for (int i = 0; i < size; ++i) {
            if (st.find(nums[i]) != st.end()) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};