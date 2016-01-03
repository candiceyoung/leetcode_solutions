class Solution {
public:
    void recursive(string &word, int start, vector<string> &result) {
        int len = word.length();
        result.push_back(word);
        for (int i = start; i < len; ++i) {
            if ((i - 1) >= 0 && word[i - 1] >= '0' && word[i - 1] <= '9') continue;
            for (int j = 1; j <= len - start; ++j) {
                if ((len - i) >= j) {
                    string temp = word;
                    word = word.substr(0, i) + to_string(j) + word.substr(j + i, len - j - i);
                    recursive(word, i + 1, result);
                    word = temp;
                }
            }
        }
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        int len = word.length();
        if (len == 0) { result.push_back(""); return result; }
        recursive(word, 0, result);
        cout << result.size() << endl;
        return result;
    }
};