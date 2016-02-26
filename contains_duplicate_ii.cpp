class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return false;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < size; ++i) {
            if (mp.find(nums[i]) == mp.end()) mp[nums[i]].push_back(i);
            else {
                for (vector<int>::iterator it = mp[nums[i]].begin(); it != mp[nums[i]].end(); ++it) {
                    if (abs(*it - i) <= k) return true;
                }
                mp[nums[i]].push_back(i);
            }
        }
        return false;
    }
};