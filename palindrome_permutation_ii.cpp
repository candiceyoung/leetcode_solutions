class Solution {
private:
    string half;
    char odd;
public:
    bool canGeneratePalindromes(string s) {
        unordered_map<char, int> m;
        int len = s.length();
        if (len == 0) return true;
        for (int i = 0; i < len; ++i) {
            if (m.find(s[i]) != m.end()) {
                // found
                m[s[i]]++;
            }
            else {
                m[s[i]] = 1;
            }
        }
        unordered_map<char, int>::iterator it;
        int count = 0;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2) {
                count++;
                odd = it->first;
            }
            for (int i = 0; i < it->second / 2; ++i) {
                half += it->first;
            }
        }
        if (len % 2) return (count == 1);
        else return (count == 0);
    }
    
    void generate(string &s, int i, vector<string> &result) {
        int len = s.length();
        if (i >= len) {
            result.push_back(s);
            return;
        }
        int j = i;
        set<char> visited;
        while (j < len) {
            if (visited.find(s[j]) != visited.end()) {
                j++;
                continue;
            }
            swap(s[i], s[j]);
            generate(s, i + 1, result);
            swap(s[j], s[i]);
            visited.insert(s[j++]);
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<string> half_result;
        vector<string> result;
        int len = s.length();
        if (len == 0) return result;
        if (!canGeneratePalindromes(s)) return result;
        sort(s.begin(), s.end());
        generate(half, 0, half_result);
        for (int i = 0; i < half_result.size(); ++i) {
            string temp = half_result[i];
            reverse(temp.begin(), temp.end());
            if (len % 2) temp = half_result[i] + odd + temp;
            else temp = half_result[i] + temp;
            result.push_back(temp);
        }
        return result;
    }
};