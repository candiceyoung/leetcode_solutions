class Solution {
public:
    bool canWin(string s) {
        int len = s.length();
        if (len == 0) return false;
        bool isMoved = false;
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                isMoved = true;
                if (!canWin(s)) return true;
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        if (!isMoved) return false;
    }
};