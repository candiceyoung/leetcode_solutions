#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    void combinations(vector<string> &result, string temp, string digits, int level, unordered_map<char, string> dict) {
        if (level == digits.size()) {
            result.push_back(temp);
            return;
        }
        string s = dict[digits[level]];
        for (int i = 0; i < s.size(); ++i) {
            temp.push_back(s[i]);
            combinations(result, temp, digits, level+1, dict);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) return result;
        unordered_map<char, string> dict;
        dict['0'] = "";
        dict['1'] = "";
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
        string temp;
        combinations(result, temp, digits, 0, dict);
        return result;
    }
};
int main(void) {
    Solution s;
    string digits = "7";
    vector<string> result = s.letterCombinations(digits);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
