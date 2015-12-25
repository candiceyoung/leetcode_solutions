#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        int size = s.length();
        if (size == 0) return result;
        for (int i = 0; i < size - 1; ++i) {
            if ((s[i] == s[i + 1]) && (s[i] == '+') ) {
                s[i] = '-';
                s[i + 1] = '-';
                result.push_back(s);
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        return result;
    }
};
int main(void) {
    Solution s;
    vector<string> result = s.generatePossibleNextMoves("++++");
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
