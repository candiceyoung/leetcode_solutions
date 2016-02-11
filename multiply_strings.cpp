class Solution {
public:
    string sum(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        if (len1 < len2) return sum(num2, num1);
        int carry = 0;
        string result;
        int i = len2 - 1, j = len1 - 1;
        while (i >= 0 && j >= 0) {
            int temp = num1[j] - '0' + num2[i] - '0' + carry;
            result = to_string(temp % 10) + result;
            carry = temp / 10;
            i--; j--;
        }
        while (j >= 0) {
            int temp = num1[j] - '0' + carry;
            result = to_string(temp % 10) + result;
            carry = temp / 10;
            j--;
        }
        if (carry) result = to_string(carry) + result;
        return result;
    }
    string multiply(string num1, string num2) {
        string result, ans = "0";
        int len1 = num1.length(), len2 = num2.length();
        if (len1 == 0 || len2 == 0) return result;
        if (num1 == "0" || num2 == "0") return "0";
        if (len1 < len2) return multiply(num2, num1);
        int carry;
        int bit = 0;
        for (int i = len2 - 1; i >= 0; --i) {
            carry = 0;
            result = "";
            for (int j = len1 - 1; j >= 0; --j) {
                int product = (num1[j] - '0') * (num2[i] - '0') + carry;
                carry = product / 10;
                result = to_string(product % 10) + result;
            }
            if (carry) result = to_string(carry) + result;
            for (int m = 0; m < bit; ++m) result += '0';
            cout << result << endl;
            ans = (ans == "0") ? result : sum(ans, result);
            bit++;
        }
        return ans;
    }
};