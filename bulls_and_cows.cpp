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

/*
class Solution {
public:
    string getHint(string secret, string guess) {
        int total_a = 0, total_b = 0;
        int len_s = secret.length();
        int len_g = guess.length();
        if (len_s != len_g) return "0A0B";
        unordered_map<char, int> mp;
        for (int i = 0; i < len_s; ++i) {
            if (secret[i] == guess[i]) total_a++;
            else {
                if (mp.find(secret[i]) == mp.end()) mp[secret[i]] = 1;
                else mp[secret[i]]++;
            }
        }
        for (int i = 0; i < len_g; ++i) {
            if (guess[i] != secret[i] && mp.find(guess[i]) != mp.end() && mp[guess[i]] > 0) { 
                total_b++;
                mp[guess[i]]--;
            }
            
        }
        return to_string(total_a) + "A" + to_string(total_b) + "B";
    }
};
*/
