class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        if (size == 0) return 0;
        vector<int> pointers(size, 0);
        vector<int> ugly;
        ugly.push_back(1);
        int counter = 1;
        while (counter < n) {
            int minUgly = INT_MAX;
            for (int i = 0; i < size; ++i) {
                minUgly = min(minUgly, ugly[pointers[i]] * primes[i]);
            }
            ugly.push_back(minUgly);
            counter++;
            for (int i = 0; i < size; ++i) {
                if (minUgly == ugly[pointers[i]] * primes[i]) pointers[i]++;
            }
        }
        return ugly[n - 1];
    }
};