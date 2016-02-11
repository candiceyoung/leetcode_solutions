class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1 || x == 1.0) return x;
        if (n == 0) return 1.0;
        if (x == -1.0 && n == INT_MIN) return 1;
        if (n < 0) return 1 / myPow(x, -n);
        double half = myPow(x, n / 2);
        if (n % 2) return half * half * x;
        else return half * half;
    }
};