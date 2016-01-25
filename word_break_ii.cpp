class Solution {
public:
    void recursive(vector<string> &result, string temp, string &s, int start, unordered_set<string> &wordDict, int minLen, int maxLen, vector<bool> &isBreakable) {
        int len = s.length();
        for (int i = minLen; i <= min(maxLen, len - start); ++i) {
            if (isBreakable[start + i] && wordDict.count(s.substr(start, i))) {
                if (start + i == len) result.push_back(temp + s.substr(start, i));
                else recursive(result, temp + s.substr(start, i) + " ", s, start + i, wordDict, minLen, maxLen, isBreakable);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        int len = s.length();
        if (len == 0) return result;
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
        string temp;
        if (isBreakable[0]) recursive(result, temp, s, 0, wordDict, minLen, maxLen, isBreakable);
        return result;
    }
};