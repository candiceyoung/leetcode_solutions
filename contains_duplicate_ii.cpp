class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < size; ++i) {
            if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = i;
            else {
                if (i - mp[nums[i]] <= k) return true;
                else mp[nums[i]] = i;
            }
        }
        return false;
    }
};