#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) return;
        reverse(s.begin(), s.end());
        string::iterator start = s.begin(), end = start;
        while (start != s.end() && end != s.end()) {
            if ((*end) == ' ') {
                reverse(start, end);
                end++;
                start = end;
            }
            else {
                end++;
            }
        }
        reverse(start, end);
    }
};
int main(void) {
    Solution s;
    string str = "Happy new year";
    s.reverseWords(str);
    cout << str << endl;
    return 0;
}
