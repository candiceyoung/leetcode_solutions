#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int size = s.length();
        for (int i = 0; i < size; ++i) {
            if (m.find(s[i]) != m.end()) {
                // found it
                m[s[i]]++;
            }
            else {
                // oops
                m[s[i]] = 1;
            }
        }
        unordered_map<char, int>::iterator it;
        if (size % 2) {
            // odd
            int count = 0;
            for (it = m.begin(); it != m.end(); ++it) {
                if (it->second % 2) count++;
            }
            if (count == 1) return true;
            else return false;
        }
        else {
            int count = 0;
            for (it = m.begin(); it != m.end(); ++it) {
                if (it->second % 2) count++;
            }
            if (count == 0) return true;
            else return false;
        }
    }
};
int main(void) {
    Solution s;
    cout << s.canPermutePalindrome("abb") << endl;
    return 0;
}
