class Solution {
public:
    vector<string> recursive(string &s, int start, int end, unordered_map<char, vector<int>> &mp) {
        vector<string> ret;
        if (start > end) return ret;
        else if (start == end && s[start] == '(') return ret;
        else if (start == end && s[start] == ')') return ret;
        else if (start == end && s[start] != '(' && s[start] != ')') {
            string temp = "";
            ret.push_back(temp + s[start]);
        }
        else if (start == end && s[start] != '(' && s[start] != ')') { string temp = "" + s[start]; ret.push_back(temp); }
        if (s[start] != '(' && s[start] != ')') {
            vector<string> result = recursive(s, start + 1, end, mp);
            string temp = "";
            if (result.size() == 0) {
                temp += s[start];
                ret.push_back(temp);
            }
            for (int i = 0; i < result.size(); ++i) {
                temp = s[start] + result[i];
                ret.push_back(temp);
            }
            return ret;
        }
        else if (s[start] == ')') {
            return recursive(s, start + 1, end, mp);
        }
        else {
            vector<string> tt = recursive(s, start + 1, end, mp);
            for (int i = 0; i < tt.size(); ++i) ret.push_back(tt[i]);
            for (vector<int>::iterator it = mp[')'].begin(); it != mp[')'].end(); ++it) {
                if (*it > start && *it <= end) {
                    vector<string> result = recursive(s, start + 1, *it - 1, mp);
                    vector<string> result2 = recursive(s, *it + 1, end, mp);
                    if (result.size() == 0) {
                        string temp = "()";
                        if (result2.size() == 0) ret.push_back(temp);
                        for (int i = 0; i < result2.size(); ++i) {
                            string tmp = temp + result2[i];
                            ret.push_back(tmp);
                        }
                    }
                    for (int i = 0; i < result.size(); ++i) {
                        if (result2.size() == 0) {
                            ret.push_back('(' + result[i] + ')');
                        }
                        for (int j = 0; j < result2.size(); ++j) {
                            string tmp = '(' + result[i] + ')' + result2[j];
                            ret.push_back(tmp);
                        }
                    }
                }
            }
            return ret;
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        vector<string> result;
        unordered_map<char, vector<int>> mp;
        int len = s.length();
        if (len == 0) { result.push_back(""); return result; }
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') mp['('].push_back(i);
            else if (s[i] == ')') mp[')'].push_back(i);
        }
        ret = recursive(s, 0, len - 1, mp);
        int maximum = INT_MIN;
        unordered_set<string> st;
        for (int i = 0; i < ret.size(); ++i) {
            maximum = max(maximum, (int)ret[i].length());
        }
        for (int i = 0; i < ret.size(); ++i) {
            if (ret[i].length() == maximum && st.find(ret[i]) == st.end()) {
                result.push_back(ret[i]);
                st.insert(ret[i]);
            }
        }
        if (result.size() == 0) result.push_back("");
        return result;
    }
};