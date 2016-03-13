class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        if (size == 0) return 0;
        vector<int> ugly(n);
        vector<int> pointers(size, 0);
        ugly[0] = 1;
        for (int i = 1; i < n; ++i) {
            int minUgly = INT_MAX;
            for (int j = 0; j < size; ++j) {
                minUgly = min(minUgly, ugly[pointers[j]] * primes[j]);
            }
            ugly[i] = minUgly;
            for (int j = 0; j < size; ++j) {
                if (minUgly == ugly[pointers[j]] * primes[j]) pointers[j]++;
            }
        }
        return ugly[n - 1];
    }
};