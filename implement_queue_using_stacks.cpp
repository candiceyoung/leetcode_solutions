class Queue {
private:
    stack<int> stk1, stk2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stk1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!stk1.empty()) {
            int tp = stk1.top();
            stk1.pop();
            stk2.push(tp);
        }
        stk2.pop();
        while (!stk2.empty()) {
            int tp = stk2.top();
            stk2.pop();
            stk1.push(tp);
        }
    }

    // Get the front element.
    int peek(void) {
        while (!stk1.empty()) {
            int tp = stk1.top();
            stk1.pop();
            stk2.push(tp);
        }
        int result = stk2.top();
        while (!stk2.empty()) {
            int tp = stk2.top();
            stk2.pop();
            stk1.push(tp);
        }
        return result;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk1.empty();
    }
};