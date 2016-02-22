class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> result;
        int len = s.length();
        if (len == 0) return result;
        for (int i = 0; i <= len - 10; ++i) {
            string temp = s.substr(i, 10);
            if (mp.find(temp) == mp.end()) mp[temp] = 1;
            else mp[temp]++;
        }
        for (unordered_map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if (it->second > 1) result.push_back(it->first);
        }
        return result;
    }
};