class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len_s = s.length(), len_t = t.length();
        if (len_s == 0 && len_t == 0) return false;
        if (abs(len_s - len_t) > 1) return false;
        else if (len_s == len_t) {
            int count = 0;
            for (int i = 0; i < len_s; ++i) {
                if (s[i] != t[i]) count++; 
            }
            if (count != 1) return false;
            else return true;
        }
        else {
            int i = 0, j = 0, count = 0;
            while (i < len_s && j < len_t) {
                if (s[i] == t[j]) {
                    i++;
                    j++;
                }
                else {
                    if (len_s > len_t) i++;
                    else j++;
                }
            }
            if (abs(i - j) > 1) return false;
            else if (i == len_s && j == len_t) return true;
            else if ((i == j) && ((len_s - i) == 1) || ((len_t - j) == 1)) return true;
            else return false;
        }
    }
};