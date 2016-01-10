class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (len == 0) return true;
        int p1 = 0, p2 = len - 1;
        while (p1 < p2) {
            if (!isalnum(s[p1])) { p1++; continue; }
            if (!isalnum(s[p2])) { p2--; continue; }
            if (tolower(s[p1]) != tolower(s[p2])) return false;
            p1++; p2--;
        }
        return true;
    }
};