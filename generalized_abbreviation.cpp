class Solution {
public:
    void recursive(vector<string> &result, int start, string &word) {
        result.push_back(word);
        for (int i = start; i < word.length(); ++i) {
            if (i - 1 >= 0 && word[i - 1] >= '0' && word[i - 1] <= '9') continue;
            for (int j = 1; j <= word.length() - i; ++j) {
                string temp = word;
                word = word.substr(0, i) + to_string(j) + word.substr(j + i, word.length() - i - j);
                recursive(result, 1 + i, word);
                word = temp;
            }
        }
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        int len = word.length();
        if (len == 0) {
            result.push_back("");
            return result;
        }
        recursive(result, 0, word);
        return result;
    }
};