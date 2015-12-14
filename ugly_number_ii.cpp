#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int h2 = 0, h3 = 0, h5 = 0;
        vector<int> ugly(n);
        ugly[0] = 1;
        for (int i = 1; i < n; ++i) {
            ugly[i] = min(ugly[h2] * 2, min(ugly[h3] * 3, ugly[h5] * 5));
            if (ugly[i] == ugly[h2] * 2) h2++;
            if (ugly[i] == ugly[h3] * 3) h3++;
            if (ugly[i] == ugly[h5] * 5) h5++;
        }
        return ugly[n - 1];
    }
};
int main(void) {
    Solution s;
    cout << s.nthUglyNumber(18) << endl;
    return 0;
}
