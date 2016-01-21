class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_needle = needle.length();
        int len_haystack = haystack.length();
        if (len_haystack < len_needle) return -1;
        for (int i = 0; i < haystack.length() - len_needle + 1; ++i) {
            if (haystack.substr(i, len_needle) == needle) return i;
        }
        return -1;
    }
};