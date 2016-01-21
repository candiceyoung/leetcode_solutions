#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0) return 0;
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        for (int i = 0; i < size; ++i) {
            minimum = min(minimum, prices[i]);
            maximum = max(maximum, prices[i] - minimum);
        }
        return maximum;
    }
};
int main(void) {
    Solution s;
    vector<int> ivec = {6, 1, 3, 2, 4, 7};
    cout << s.maxProfit(ivec) << endl;
    return 0;
}
