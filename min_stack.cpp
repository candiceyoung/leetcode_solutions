class MinStack {
private:
    stack<int> stk1, stk2;
public:
    void push(int x) {
        stk1.push(x);
        if (stk2.size() == 0 || stk2.top() >= x) {
            stk2.push(x);
        }
    }

    void pop() {
        int temp = stk1.top();
        stk1.pop();
        if (temp == stk2.top()) stk2.pop();
    }

    int top() {
        return stk1.top();
    }

    int getMin() {
        return stk2.top();
    }
};