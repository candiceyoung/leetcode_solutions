#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        vector<int> d;
        if (s.length() == 0 || s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        d.push_back(1);
        d.push_back(1);
        for (int i = 1; i < s.length(); ++i) {
            int ones = s[i] - '0';
            int tens = s[i - 1] - '0';
            if (ones == 0) {
                if (tens == 1 || tens == 2) d.push_back(d[i - 1]);
                else return 0;
            }
            else {
                int num = tens * 10 + ones;
                if (11 <= num && num <= 26) {
                    d.push_back(d[i - 1] + d[i]);
                }
                else {
                    d.push_back(d[i]);
                }
            }
        }
        return d[s.length()];
    }
};
int main(void) {
    string str = "100";
    Solution s;
    cout << s.numDecodings(str) << endl;
    return 0;
}
