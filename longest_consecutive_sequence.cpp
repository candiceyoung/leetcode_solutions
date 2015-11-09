#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = true;
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int length = 1;
            int flag = nums[i];
            mp.erase(nums[i]);
            while (mp.find(flag+1) != mp.end()) {
                mp.erase(++flag);
                length++;
            }
            flag = nums[i];
            while (mp.find(flag-1) != mp.end()) {
                mp.erase(--flag);
                length++;
            }
            res = (length > res) ? length : res;
        }
        return res;
    }
};
int main(void) {
    Solution s;
    vector<int> nums = {100, 4, 101, 6, 7, 5, 3, 8};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}
