class Solution {
public:
    string next(string start) {
        string result;
        int len = start.length();
        if (len == 0) return result;
        char pre = start[0];
        int num = 1;
        for (int i = 1; i < len; ++i) {
            if (start[i] == pre) {
                num++;
            }
            else {
                result += to_string(num) + pre;
                pre = start[i];
                num = 1;
            }
        }
        result += to_string(num) + pre;
        return result;
    }
    string countAndSay(int n) {
        string start = "1";
        for (int i = 0; i < n - 1; ++i) {
            start = next(start);
        }
        return start;
    }
};