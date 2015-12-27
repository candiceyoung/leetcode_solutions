class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int size = preorder.size();
        if (size == 0) return true;
        stack<int> s;
        int bound = INT_MIN;
        for (int i = 0; i < size; ++i) {
            int value = preorder[i];
            if (value < bound) return false;
            while (!s.empty() && value > s.top()) {
                bound = s.top();
                s.pop();
            }
            s.push(value);
        }
        return true;
    }
};