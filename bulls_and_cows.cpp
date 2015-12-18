#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        string result;
        if (secret.length() == 0 || secret.length() != guess.length()) return "0A0B";
        int num_A = 0, num_B = 0;
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) num_A++;
            else {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; ++i) {
            num_B += min(s[i], g[i]);
        }
        result = to_string(num_A) + 'A' + to_string(num_B) + 'B';
        return result;
    }
};
int main(void) {
    Solution s;
    cout << s.getHint("1123", "0111") << endl;
    return 0;
}
