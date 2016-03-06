class Solution {
public:
    vector<string> convert(string version) {
        vector<string> result;
        int pos = 0;
        while (version.find('.', pos) != string::npos) {
            string temp = version.substr(pos, version.find('.', pos) - pos);
            result.push_back(temp);
            pos = version.find('.', pos);
            pos++;
        }
        result.push_back(version.substr(pos, version.length() - pos));
        return result;
    }
    bool isZero(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '0') return false;
        }
        return true;
    }
    int compareVersion(string version1, string version2) {
        int len1 = version1.length(), len2 = version2.length();
        if (len1 == 0 || len2 == 0) return 0;
        vector<string> first = convert(version1);
        vector<string> second = convert(version2);
        int i = 0;
        while (i < first.size() && i < second.size()) {
            string s1 = first[i], s2 = second[i];
            int l1 = s1.length(), l2 = s2.length();
            if (l1 > l2) {
                for (int j = 0; j < l1 - l2; ++j) s2 = "0" + s2;
            }
            else if (l1 < l2) {
                for (int j = 0; j < l2 - l1; ++j) s1 = "0" + s1;
            }
            if (s1 == s2) {
                i++; 
                continue;
            }
            else return (s1 > s2) ? 1 : -1;
        }
        if (i >= first.size() && i < second.size()) {
            for (int j = i; j < second.size(); ++j) {
                if (!isZero(second[j])) return -1;
            }
        }
        else if (i >= second.size() && i < first.size()) {
            for (int j = i; j < first.size(); ++j) {
                if (!isZero(first[j])) return 1;
            }
        }
        return 0;
    }
};