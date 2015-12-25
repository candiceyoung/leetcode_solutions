class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int low = 0, high = size - 1;
        vector<int> result;
        if (size == 0) return result;
        while (1) {
            if ((numbers[low] + numbers[high]) > target) {
                high--;
            }
            else if ((numbers[low] + numbers[high]) < target) {
                low++;
            }
            else {
                result.push_back(low + 1);
                result.push_back(high + 1);
                return result;
            }
        }
        return result;
    }
};