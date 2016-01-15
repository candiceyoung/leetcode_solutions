class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if (size == 0) return digits;
        int carry = 0;
        int j = size - 1;
        int temp = digits[j] + 1;
        if (temp > 9) {
            digits[j] = 0;
            carry = 1;
        }
        else digits[j] = temp;
        while (carry == 1 && j > 0) {
            j--;
            int temp = digits[j] + carry;
            if (temp > 9) {
                carry = 1;
                digits[j] = 0;
            }
            else {
                carry = 0;
                digits[j] = temp;
            }
        }
        if (carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};