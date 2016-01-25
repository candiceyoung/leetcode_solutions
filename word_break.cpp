class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        if (len == 0) return false;
        vector<bool> isBreakable(len+1, false);
        isBreakable[len] = true;
        int minLen = INT_MAX, maxLen = INT_MIN;
        for (string word : wordDict) {
            minLen = min(minLen, (int)word.length());
            maxLen = max(maxLen, (int)word.length());
        }
        for (int i = len - minLen; i >= 0; --i) {
            for (int j = minLen; j <= min(maxLen, len - i); ++j) {
                if (isBreakable[i + j] && wordDict.count(s.substr(i, j))) {
                    isBreakable[i] = true;
                    break;
                }
            }
        }
        return isBreakable[0];
    }
};