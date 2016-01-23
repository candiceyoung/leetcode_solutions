class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while (n != 1 && st.find(n) == st.end()) {
            st.insert(n);
            int result = 0;
            while (n) {
                int bit = n % 10;
                result += bit * bit;
                n = n / 10;
            }
            n = result;
        }
        if (n == 1) return true;
        else return false;
    }
};