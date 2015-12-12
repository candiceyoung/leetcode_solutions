#include <iostream>
#include <stdlib.h>
#include <climits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return dividend > 0 ? INT_MAX : INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isNeg = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) isNeg = true;
        unsigned long long dvd = abs((long long)dividend);
        unsigned long long dvs = abs((long long)divisor);
        unsigned long long divs  = dvs;
        int i = 0;
        while (dvs<<(i+1) <= dvd) i++;
        int res = 0;
        while (dvd >= divs) {
            if (dvd >= dvs <<i) {
                dvd -= dvs << i;
                res += 1 << i;
            }
            i--;
        }
        return isNeg ? -res : res; 
    }
};
int main(void) {
    Solution s;
    cout << s.divide(-5, 2) << endl;
    return 0;
}
