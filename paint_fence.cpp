class Solution {
public:
    int numWays(int n, int k) {
        if (k == 0 || n == 0) return 0;
        if (n == 1) return k;
        int a = k, b = k * (k - 1), c = 0;
        for (int i = 3; i <= n; ++i) {
            c = (k - 1) * (a + b);
            a = b;
            b = c;
        }
        return a+b;
    }
};