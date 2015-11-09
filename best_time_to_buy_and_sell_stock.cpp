#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, max = 0;
        vector<int>::iterator it;
        for (it = prices.begin(); it < prices.end(); ++it) {
            if (*it < min) min = *it;
            int diff = *it - min;
            if (max < diff) max = diff;
        }
        return max;
    }
};
int main(void) {
    Solution s;
    vector<int> ivec = {6, 1, 3, 2, 4, 7};
    cout << s.maxProfit(ivec) << endl;
    return 0;
}
