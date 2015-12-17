#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int c = 0;
        while (m != n) {
            m = m >> 1;
            n = n >> 1;
            c++;
        }
        return n << c;
    }
};
int main(void) {
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
