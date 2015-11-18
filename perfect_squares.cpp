#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> D(n + 1);
        D[0] = 0;
        D[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = int(sqrt(i));
            int min = D[i - temp * temp] + 1;
            for (int j = temp - 1; j > 0; --j) {
                if (min > D[i - j * j] + 1) min = D[i - j * j] + 1;
            }
            D[i] = min;
        }
        return D[n];
    }
};
int main(void) {
    Solution s;
    cout << s.numSquares(71) << endl;
    cout << s.numSquares(72) << endl;
    cout << s.numSquares(73) << endl;
    return 0;
}
