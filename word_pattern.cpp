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

/*
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern == "" || str == "") return false;
        int pos = 0;
        int i = 0;
        unordered_map<string, char> mp;
        set<char> st;
        while (str.find(" ", pos) != string::npos) {
            string word = str.substr(pos, str.find(" ", pos) - pos);
            pos = str.find(" ", pos) + 1;
            if (mp.find(word) == mp.end() && st.find(pattern[i]) == st.end()) {
                st.insert(pattern[i]);
                mp[word] = pattern[i];
            }
            else if (mp.find(word) != mp.end() && mp[word] != pattern[i]) return false;
            else if (mp.find(word) == mp.end() && st.find(pattern[i]) != st.end()) return false;
            i++;
        }
        if (pos == 0 && i == 0) {
            if (pattern.length() == 1) return true;
            else return false;
        }
        string word = str.substr(pos, str.length() - pos);
        if (mp.find(word) == mp.end() && st.find(pattern[i]) == st.end()) {
            st.insert(pattern[i]);
            mp[word] = pattern[i];
        }
        else if (mp.find(word) != mp.end() && mp[word] != pattern[i]) return false;
        else if (mp.find(word) == mp.end() && st.find(pattern[i]) != st.end()) return false;
        return true;
    }
};
*/
