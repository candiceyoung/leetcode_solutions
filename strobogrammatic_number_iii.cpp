class Solution {
public:
    bool compareString(string s1, string s2) {
        // if s1 <= s2, return true;
        if (s1.length() != s2.length()) return false;
        int i = 0;
        for (; i < s1.length(); ++i) {
            if (s1[i] < s2[i]) return true;
            else if (s1[i] == s2[i]) continue;
            else return false;
        }
        if (i == s1.length()) return true;
        else return false;
    }
    void recursive(string temp, vector<char> &nums1, vector<char> &nums2, string &low, string &high, int &total) {
        int len = temp.length();
        if (len > low.length() && len < high.length()) {
            if (len > 1 && temp[0] != '0') total++;
        }
        else if (len == low.length() && len < high.length()) {
            if (compareString(low, temp)) { 
                if (len > 1 && temp[0] == '0');
                else total++;
            }
        }
        else if (len == high.length() && len > low.length()) {
            if (compareString(temp, high)) { 
                if (len > 1 && temp[0] == '0');
                else total++;
            }
        }
        else if (len > high.length()) {
            return;
        }
        else if (len == low.length() && len == high.length()) {
            if (compareString(temp, high) && compareString(low, temp)) {
                if (len > 1 && temp[0] == '0');
                else total++;
            }
        }
        for (int i = 0; i < nums1.size(); ++i) {
            recursive(nums1[i] + temp + nums2[i], nums1, nums2, low, high, total);
        }
    }
    int strobogrammaticInRange(string low, string high) {
        int len_low = low.length();
        int len_high = high.length();
        int total = 0;
        if (len_low == 0 || len_high == 0) return 0;
        vector<char> nums1 = {'0', '1', '6', '8', '9'};
        vector<char> nums2 = {'0', '1', '9', '8', '6'};
        recursive("", nums1, nums2, low, high, total);
        recursive("0", nums1, nums2, low, high, total);
        recursive("1", nums1, nums2, low, high, total);
        recursive("8", nums1, nums2, low, high, total);
        return total;
    }
};