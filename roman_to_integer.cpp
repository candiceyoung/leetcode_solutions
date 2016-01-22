class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int len = s.length();
        if (len == 0) return 0;
        char ch;
        int result = 0;
        for (int i = 0; i < len - 1; ++i) {
            ch = s[i];
            if (mp.find(ch) == mp.end()) return 0;
            if (mp[ch] < mp[s[i + 1]]) result -= mp[ch];
            else result += mp[ch];
        }
        result += mp[s[len - 1]];
        return result;
    }
};