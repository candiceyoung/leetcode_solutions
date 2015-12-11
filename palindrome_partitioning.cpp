#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool is_palindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void recursion(string s, int i, vector<vector<string>> &result, vector<string> &temp) {
        if (i >= s.length()) {
            result.push_back(temp);
            return;
        }
        int j = i;
        while (j < s.length()) {
            if (is_palindrome(s, i, j) == false) {
                j++;
                continue;
            }
            string sub = s.substr(i, j - i + 1);
            temp.push_back(sub);
            recursion(s, j + 1, result, temp);
            temp.pop_back();
            j++;
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        if (s.length() == 0) return result;
        recursion(s, 0, result, temp);
        return result;
    }
};
int main(void) {
    Solution s;
    vector<vector<string>> result;
    result = s.partition("efe");
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
