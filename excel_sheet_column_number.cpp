class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        if (len == 0) return 0;
        int total = 0;
        for (int i = 0; i < len; ++i) {
            total = total * 26 + s[i] - 'A' + 1;
        }
        return total;
    }
};