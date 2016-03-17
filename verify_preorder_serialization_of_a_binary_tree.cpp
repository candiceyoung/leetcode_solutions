class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.length();
        if (len == 0) return true;
        stack<string> stk;
        int pos = 0;
        preorder += ',';
        while (preorder.find(',', pos) != string::npos) {
            string temp = preorder.substr(pos, preorder.find(',', pos) - pos);
            stk.push(temp);
            pos = preorder.find(',', pos);
            pos++;
            
            while (stk.top() == "#" && stk.size() > 2) {
                stk.pop();
                string second = stk.top();
                if (second != "#") {
                    stk.push("#");
                    break;
                }
                else {
                    stk.pop();
                    if (stk.size() == 1 && stk.top() == "#") return false;
                    stk.pop();
                    stk.push("#");
                }
            }
        }
        if (stk.size() == 1 && stk.top() == "#") return true;
        else return false;
    }
};