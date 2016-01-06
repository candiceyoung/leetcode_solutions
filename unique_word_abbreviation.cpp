class ValidWordAbbr {
private:
    unordered_map<string, set<string>> m;
public:
    string Abbr(string s) {
        int len = s.length();
        if (len <= 2) return s;
        else return s[0] + to_string(len - 2) + s[len - 1];
    }
    ValidWordAbbr(vector<string> &dictionary) {
        for (int i = 0; i < dictionary.size(); ++i) {
            string abbre = Abbr(dictionary[i]);
            m[abbre].insert(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        string temp = Abbr(word);
        if (m.find(temp) == m.end()) return true;
        else {
            if (m[temp].count(word) == m[temp].size()) return true;
        }
        return false;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");