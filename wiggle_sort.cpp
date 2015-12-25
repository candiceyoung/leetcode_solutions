class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int direction = 0;
        int size = nums.size();
        if (size == 0) return;
        for (int i = 0; i < size - 1; ++i) {
            if ((direction == 0) && (nums[i] > nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            }
            if ((direction == 1) && (nums[i] < nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            }
            direction = 1 - direction;
        }
    }
};