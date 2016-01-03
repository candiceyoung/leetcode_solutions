class Solution {
private:
    // this hash is very important to decrease time complexity!!!
    std::hash<std::string> str_hash;
    unordered_map<size_t, bool> m;
public:
    bool isScr(string s1, int start1, int end1, string s2, int start2, int end2) {
        bool result = false;
        string s = s1.substr(start1, end1 - start1 + 1) + "#" + s2.substr(start2, end2 - start2 + 1);
        if (m.find(str_hash(s)) != m.end()) return m[str_hash(s)];
        
        if ((end1 - start1) != (end2 - start2)) result = false;
        if ((end1 < start1) || (end2 < start2)) result = false;
        if (s1.substr(start1, (end1 - start1 + 1)) == s2.substr(start2, (end2 - start2 + 1))) result = true;
        if (start1 == end1) result = (s1[start1]==s2[start2]);
        
        for (int i = 0; i < (end1 - start1); ++i) {
            if (isScr(s1, start1, start1 + i, s2, start2, start2 + i) && isScr(s1, start1 + i + 1, end1, s2, start2 + i + 1, end2)) result = true;
            if (isScr(s1, start1, start1 + i, s2, end2 - i, end2) && isScr(s1, start1 + i + 1, end1, s2, start2, end2 - i - 1)) result = true;
        }
        m[str_hash(s)] = result;
        return result;
    }
    bool isScramble(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 != len2) return false;
        if (len1 == 0) return true;
        return isScr(s1, 0, len1 - 1, s2, 0, len2 - 1);
    }
};