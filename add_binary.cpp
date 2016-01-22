class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();
        if (len_a == 0) return b;
        if (len_b == 0) return a;
        string shorter = (len_a < len_b) ? a : b;
        string longer = (len_a < len_b) ? b : a;
        int len_s = shorter.length();
        int len_l = longer.length();
        for (int i = 0; i < len_l - len_s; ++i) {
            shorter = '0' + shorter;
        }
        string result = "";
        int carry = 0;
        for (int i = len_l - 1; i >= 0; --i) {
            int t1 = longer[i] - '0';
            int t2 = shorter[i] - '0';
            if (t1 + t2 + carry == 2) {
                carry = 1;
                result = "0" + result;
            }
            else if (t1 + t2 + carry == 3) {
                carry = 1;
                result = "1" + result;
            }
            else if (t1 + t2 + carry <= 1) {
                result = to_string(t1 + t2 + carry) + result;
                carry = 0;
            }
        }
        if (carry == 1) result = "1" + result;
        return result;
    }
};