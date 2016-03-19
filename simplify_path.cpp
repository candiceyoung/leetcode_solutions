class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string result;
        int len = path.length();
        if (len == 0) return result;
        if (path[0] != '/') return result;
        int pos = 1;
        while (path.find('/', pos) != string::npos) {
            string current = path.substr(pos, path.find('/', pos) - pos);
            pos = path.find('/', pos);
            pos++;
            if (current == ".") continue;
            else if (current == ".." && !stk.empty()) stk.pop();
            else if (current == ".." && stk.empty()) continue;
            else if (current.length() == 0) continue;
            else stk.push(current);
        }
        if (pos <= len - 1) {
            string current = path.substr(pos, len - pos);
            if (current == ".");
            else if (current == ".." && !stk.empty()) stk.pop();
            else if (current == ".." && stk.empty());
            else if (current.length() == 0);
            else stk.push(current);
        }
        if (stk.empty()) return "/";
        while (!stk.empty()) {
            string temp = stk.top();
            stk.pop();
            result = "/" + temp + result;
        }
        return result;
    }
};
/*
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string result;
        int len = path.length();
        if (len == 0) return result;
        if (path[0] != '/') return result;
        int pos = 1;
        path += '/';
        while (path.find('/', pos) != string::npos) {
            string current = path.substr(pos, path.find('/', pos) - pos);
            pos = path.find('/', pos);
            pos++;
            if (current == ".") continue;
            else if (current == ".." && !stk.empty()) stk.pop();
            else if (current == ".." && stk.empty()) continue;
            else if (current.length() == 0) continue;
            else stk.push(current);
        }
        if (stk.empty()) return "/";
        while (!stk.empty()) {
            string temp = stk.top();
            stk.pop();
            result = "/" + temp + result;
        }
        return result;
    }
};
*/