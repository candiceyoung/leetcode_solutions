class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size < 3) return 0;
        int total = 0;
        for (int i = 0; i < size - 2; ++i) {
            int p1 = i + 1, p2 = size - 1;
            while (p1 < p2) {
                if (nums[i] + nums[p1] + nums[p2] < target) {
                    total += p2 - p1;
                    p1++;
                } 
                else p2--;
            }
        }
        return total;
    }
};