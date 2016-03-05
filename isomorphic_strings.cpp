class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        if (len_s == 0 && len_t == 0) return true;
        else if (len_s == 0 || len_t == 0) return false;
        if (len_s != len_t) return false;
        unordered_map<char, char> mp;
        set<char> st;
        for (int i = 0; i < len_s; ++i) {
            if (mp.find(s[i]) == mp.end()) {
                if (st.count(t[i]) == 0) {
                    mp[s[i]] = t[i];
                    st.insert(t[i]);
                }
                else return false;
            }
            else {
                if (mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};