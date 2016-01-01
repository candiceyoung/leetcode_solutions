class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        int size = strings.size();
        if (size == 0) return result;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < size; ++i) {
            string temp = strings[i];
            int diff = temp[0] - 'a';
            for (int j = 0; j < strings[i].length(); ++j) {
                if (temp[j] - 'a' - diff >= 0) temp[j] = temp[j] - diff;
                else temp[j] = temp[j] - diff + 26;
            }
            m[temp].push_back(strings[i]);
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            result.push_back(it->second);
        }
        sort(result.begin(), result.end());
        return result;
    }
};