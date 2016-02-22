class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> priority;
        priority['+'] = 1;
        priority['-'] = 1;
        priority['*'] = 2;
        priority['/'] = 2;
        stack<int> nums;
        stack<char> operators;
        int len = s.length();
        if (len == 0) return 0;
        int flag = 0;
        int mul = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') continue;
            else if (s[i] >= '0' && s[i] <= '9' && flag == 0) {
                nums.push(s[i] - '0'); flag = 1;
            }
            else if (s[i] >= '0' && s[i] <= '9' && flag == 1) {
                int temp = nums.top();
                nums.pop();
                nums.push(temp * 10 + s[i] - '0');
            }
            else {
                // +-*/
                flag = 0;
                if (operators.empty()) operators.push(s[i]);
                else {
                    int last_priority = priority[operators.top()];
                    int current_priority = priority[s[i]];
                    while (last_priority >= current_priority) {
                        if (nums.size() < 2) return 0;
                        int n1 = nums.top();
                        nums.pop();
                        int n2 = nums.top();
                        nums.pop();
                        char op = operators.top();
                        int result;
                        if (op == '+') result = n1 + n2;
                        else if (op == '-') result = n2 - n1;
                        else if (op == '*') result = n1 * n2;
                        else result = n2 / n1;
                        operators.pop();
                        nums.push(result);
                        if (operators.empty()) break;
                        last_priority = priority[operators.top()];
                    }
                    operators.push(s[i]);
                }
            }
        }
        while (!operators.empty()) {
            char op = operators.top();
            operators.pop();
            int n1 = nums.top();
            nums.pop();
            int n2 = nums.top();
            nums.pop();
            int result;
            if (op == '+') result = n1 + n2;
            else if (op == '-') result = n2 - n1;
            else if (op == '*') result = n1 * n2;
            else result = n2 / n1;
            nums.push(result);
        }
        if (nums.empty()) return 0;
        else return nums.top();
    }
};