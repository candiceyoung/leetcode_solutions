class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> nums;
        stack<char> operators;
        int result = 0, flag = 0;
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') continue;
            else if (s[i] >= '0' && s[i] <= '9' && flag == 0) {
                nums.push(s[i] - '0');
                flag = 1;
            }
            else if (s[i] >= '0' && s[i] <= '9' && flag == 1) {
                int temp = nums.top();
                nums.pop();
                nums.push(temp * 10 + s[i] - '0');
            }
            else {
                //+-()
                flag = 0;
                if (s[i] == '(') operators.push('(');
                else if (s[i] == ')') {
                    char op = operators.top();
                    while (op != '(') {
                        operators.pop();
                        int num1 = nums.top();
                        nums.pop();
                        int num2 = nums.top();
                        nums.pop();
                        result = (op == '+') ? num2 + num1 : num2 - num1;
                        nums.push(result);
                        op = operators.top();
                    }
                    operators.pop();
                }
                else {
                    if (!operators.empty() && operators.top() != '(') {
                        int num1 = nums.top();
                        nums.pop();
                        int num2 = nums.top();
                        nums.pop();
                        char op = operators.top();
                        operators.pop();
                        result = (op == '+') ? num2 + num1 : num2 - num1;
                        operators.push(s[i]);
                        nums.push(result);
                    }
                    else operators.push(s[i]);
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
            nums.push(result);
        }
        if (nums.empty()) return 0;
        else return nums.top();
    }
};