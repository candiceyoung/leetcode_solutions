class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (len == 0) return true;
        stack<char> stk;
        for (int i = 0; i < len; ++i) {
            if (stk.empty()) {
                stk.push(s[i]);
                continue;
            }
            if (stk.top() == '(' && s[i] == ')' || stk.top() == '[' && s[i] == ']' || stk.top() == '{' && s[i] == '}') {
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }
        if (stk.empty()) return true;
        else return false;
    }
};