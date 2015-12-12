#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern == "" || str == "") return false;
        unordered_map<string, char> dict;
        vector<string> words;
        set<char> s;
        int start = 0, end = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ') {
                end = i - 1;
                words.push_back(str.substr(start, end - start + 1));
                start = i + 1;
            }
        }
        words.push_back(str.substr(start, str.length() - start));
        if (pattern.length() != words.size()) return false;
        for (int i = 0; i < words.size(); ++i) {
            if (dict.find(words[i]) != dict.end() && pattern[i] != dict[words[i]]) return false; 
            else if (dict.find(words[i]) == dict.end() && (s.find(pattern[i]) == s.end())) {
                dict[words[i]] = pattern[i];
                s.insert(pattern[i]);
            }
            else if (dict.find(words[i]) == dict.end() && (s.find(pattern[i]) != s.end())) return false;
        }
        return true;
    }
};
int main(void) {
    string pattern = "abba";
    string str = "dog cat cat do";
    Solution s;
    cout << s.wordPattern(pattern, str) << endl;
    return 0;
}
