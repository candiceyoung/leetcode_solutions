class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        if (n == pow(2, (int)(log10(n) / log10(2)))) return true;
        else return false;
    }
};