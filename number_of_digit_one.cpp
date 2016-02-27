class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        string num;
        int temp = n;
        while (temp) {
            num = to_string(temp % 10) + num;
            temp = temp / 10;
        }
        int len = num.length();
        int left, right, total = 0, right_value;
        for (int i = 0; i < len; ++i) {
            left = 0; right = 0; right_value = 0;
            string left_str = num.substr(0, i);
            for (int j = 0; j < left_str.length(); ++j) {
                left = left * 10 + left_str[j] - '0';
            }
            string right_str = num.substr(i + 1, len - i - 1);
            for (int j = 0; j < right_str.length(); ++j) {
                right_value = right_value * 10 + right_str[j] - '0';
            }
            left++;
            if (num[i] - '0' > 1) {
                right = pow(10, len - i - 1);
                total += left * right;
            }
            else if (num[i] - '0' == 1) {
                right = pow(10, len - i - 1);
                total += (left - 1) * right + right_value + 1;
            }
            else if (num[i] - '0' == 0) {
                right = pow(10, len - i - 1);
                total += (left - 1) * right;
            }
        }
        return total;
    }
};