class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.length();
        if (len == 0) return s;
        vector<int> last(26, 0);
        vector<bool> included(26, false);
        string result;
        for (int i = len - 1; i >= 0; --i) {
            if (!last[s[i] - 'a']) {
                last[s[i] - 'a'] = i;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (!included[s[i] - 'a']) {
                while (!result.empty() && s[i] < result.back() && last[result.back() - 'a'] > i) {
                    included[result.back() - 'a'] = 0;
                    result.pop_back();
                }
                included[s[i] - 'a'] = 1;
                result.push_back(s[i]);
            }
        }
        return result;
    }
};