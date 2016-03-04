class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        while (n) {
            if (n % 2) total++;
            n = n / 2;
        }
        return total;
    }
};