class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, m = 0;
        vector<int> charIndex(256, -1);
        for (int i = 0; i < s.length(); ++i) {
            m = max(charIndex[s[i]] + 1, m);
            charIndex[s[i]] = i;
            longest = max(longest, i - m + 1);
        }
        return longest;
    }
};

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0) return 0;
        unordered_map<char, int> mp;
        int maximum = 1;
        int p1 = 0, p2 = 0;
        while (p1 <= p2 && p2 < len) {
            if (p1 == p2) {
                p2++;
                mp[s[p1]] = p1;
                continue;
            }
            if (mp.find(s[p2]) == mp.end()) {
                mp[s[p2]] = p2;
                maximum = max(maximum, p2 - p1 + 1);
                p2++;
            }
            else {
                int temp = mp[s[p2]];
                for (int i = p1; i < temp; ++i) {
                    mp.erase(s[i]);
                }
                p1 = temp + 1;
                mp[s[p2]] = p2;
                maximum = max(maximum, p2 - p1 + 1);
                p2++;
            }
        }
        return maximum;
    }
};
*/