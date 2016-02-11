class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return;
        int p0 = 0, p2 = size - 1;
        int i = 0;
        while (i <= p2 && p0 < size && p2 >= 0) {
            if (nums[i] == 1) {
                i++;
                continue;
            }
            else if (nums[i] == 0) {
                if (i >= p0) swap(nums[p0++], nums[i]);
                else i++;
            }
            else if (nums[i] == 2) {
                if (i <= p2) swap(nums[p2--], nums[i]);
                else i--;
            }
        }
    }
};