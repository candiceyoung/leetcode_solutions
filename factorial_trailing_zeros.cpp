class Solution {
public:
    int trailingZeroes(int n) {
        int total = n / 5;
        long long x = 25;
        while (n >= x) {
            total += n / x;
            x *= 5;
        }
        return total;
    }
};