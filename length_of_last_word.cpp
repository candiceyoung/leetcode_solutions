class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        if (len == 0) return 0;
        bool flag = false;
        int total = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (!flag && s[i] == ' ') continue;
            else if (s[i] != ' ') {
                flag = true;
                total++;
            }
            else if (flag && s[i] == ' ') return total;
        }
        return total;
    }
};