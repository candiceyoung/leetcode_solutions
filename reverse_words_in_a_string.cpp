#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        bool hasMetChar = false;
        int len = 0;
        // first remove all the leading, and duplicate spaces
        for (int i = 0; i < s.length(); ++i) {
            if (!hasMetChar) {
                if (s[i] != ' ') {
                    hasMetChar = true;
                    s[len++] = s[i];
                }
            }
            else {
                if (s[i] != ' ' || s[len - 1] != ' ') {
                    s[len++] = s[i];
                }
            }
        }
        // remove the last space if there is
        if (len > 0 && s[len - 1] == ' ') len--;
        // shrink the string
        s.resize(len);
        reverse(s.begin(), s.end());
        string::iterator start = s.begin(), end = start;
        while (start != s.end() && end != s.end()) {
            if (*end == ' ') {
                reverse(start, end);
                end++;
                start = end;
            }
            else end++;
        }
        reverse(start, end);
    }
};
int main(void) {
    Solution s;
    string str = "   hello   world  ";
    s.reverseWords(str);
    cout << str << endl;
    return 0;
}
