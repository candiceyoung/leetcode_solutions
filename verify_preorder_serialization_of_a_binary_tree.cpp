class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> stk;
        int len = preorder.length();
        if (len == 0) return true;
        int pos = 0;
        preorder += ',';
        while (preorder.find(',', pos) != string::npos) {
            string temp = preorder.substr(pos, preorder.find(',', pos) - pos);
            stk.push(temp);
            pos = preorder.find(',', pos);
            pos++;
            
            if (stk.size() < 2) continue;
            while (stk.size() > 2) {
                string first = stk.top();
                stk.pop();
                string second = stk.top();
                stk.pop();
                if (first == "#" && second == "#") {
                    if (stk.top() == "#") return false;
                    else {
                        stk.pop();
                        stk.push("#");
                    }
                }
                else {
                    stk.push(second);
                    stk.push(first);
                    break;
                }
            }
        }
        if (stk.size() == 1 && stk.top() == "#") return true;
        else return false;
    }
};