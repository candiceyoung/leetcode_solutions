class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int size = digits.size();
        if (size == 0) return result;
        int carry = 0;
        for (int i = size - 1; i >= 0; --i) {
            int temp = ((i == size - 1) ? 1 : 0) + carry + digits[i];
            result.push_back(temp % 10);
            carry = temp / 10;
        }
        if (carry) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};