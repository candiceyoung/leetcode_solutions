class Solution {
public:
    /*
    Solution 1:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return;
        vector<int> copy;
        for (int i = 0; i < size; ++i) {
            copy.push_back(nums[i]);
        }
        for (int i = 0; i < size; ++i) {
            nums[(i + k) % size] = copy[i];
        }
    }
    */
    /*
    Solution 2:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return;
        k = k % size;
        reverse(nums.begin(), nums.begin() + size - k);
        reverse(nums.begin() + size - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
    */
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return;
        int total = 0, start = 0, current = 0;
        int numToBeRotated = nums[0];
        int tmp = 0;
        while (total < size) {
            do {
                tmp = nums[(current + k) % size];
                nums[(current + k) % size] = numToBeRotated;
                numToBeRotated = tmp;
                current = (current + k) % size;
                total++;
            } while (start != current);
            start++;
            current = start;
            numToBeRotated = nums[start];
        }
    }
};