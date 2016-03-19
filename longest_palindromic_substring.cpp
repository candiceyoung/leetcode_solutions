class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) return s;
        int max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right] == s[right + 1]) right++;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }
            if (max_len < right - left + 1) {
                max_len = right - left + 1;
                max_left = left;
            }
        }
        return s.substr(max_left, max_len);
    }
};