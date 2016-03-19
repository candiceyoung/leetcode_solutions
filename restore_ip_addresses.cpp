#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void dfs(string s, int number, int start, vector<string>& result, string ip) {
        if (number == 4 && start == s.size()) {
            ip.erase(ip.end() - 1);
            result.push_back(ip);
            return;
        }
        // the rest string is too long
        if ((s.size() - start) > (4 - number) * 3) {
            return;
        }
        // the rest string is too short
        if ((s.size() - start) < (4 - number)) {
            return;
        }
        int num = 0;
        for (int i = start; i < start + 3; ++i) {
            num = num * 10 + s[i] - '0';
            if (num < 256) {
                ip = ip + s[i];
                dfs(s, number+1, i+1, result, ip+'.');
            }
            if (num == 0) break;
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.size() < 4) return result;
        string ip;
        dfs(s, 0, 0, result, ip);
        return result;
    }
};
int main(void) {
    Solution s;
    string raw = "25525511135";
    string raw1 = "0000";
    vector<string> result = s.restoreIpAddresses(raw1);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}

/*
class Solution {
public:
    void recursive(vector<string> &result, string &temp, int total, int start, string &s) {
        if (total == 4 && start == s.size()) {
            temp.erase(temp.end() - 1);
            result.push_back(temp);
            return;
        }
        if (s.size() - start > (4 - total) * 3) return;
        if (s.size() - start < (4 - total) * 1) return;
        for (int i = 1; i < 4; ++i) {
            string tt = temp;
            string sub = s.substr(start, i);
            int sub_value = stoi(sub, nullptr, 10);
            if (sub.size() != 1 && sub[0] == '0') continue;
            if (sub_value <= 255 && sub_value >= 0) {
                tt += sub + '.';
                recursive(result, tt, total + 1, start + i, s);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int size = s.size();
        if (size < 4) return result;
        string temp;
        recursive(result, temp, 0, 0, s);
        return result;
    }
};
*/
