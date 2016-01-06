class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int head = 0;
        int len = s.length();
        set<char> characters;
        int longest = INT_MIN;
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            characters.insert(s[i]);
            if (characters.size() <= 2) {
                sum = i - head + 1;
                longest = max(longest, sum);
            }
            else {
                head = i - 1;
                while (head - 1 >= 0 && s[head] == s[head - 1]) head--;
                characters.erase(s[head - 1]);
            }
        }
        return (longest == INT_MIN) ? 0 : longest;
    }
};