#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            vector<int>::iterator it;
            int maxProfit = 0;
            int start, end;
            int flag = 0;
            for (it = prices.begin(); it < prices.end() - 1; ++it) {
                if ((*it <= *(it + 1)) && (!flag)) {
                    start = *it;
                    flag = 1;
                }
                else if ((*it > *(it + 1)) && flag) {
                    end = *it;
                    flag = 0;
                    maxProfit += (end - start);
                }
            }
            if (*it >= *(it - 1)) {
                end = *it;
                maxProfit += (end - start);
            }
            return maxProfit;
        }
};
int main(void) {
    Solution s;
    vector<int> ivec = {1, 9, 6, 9, 1, 7, 1, 1, 5, 9, 9, 9};
    cout << s.maxProfit(ivec) << endl;
    return 0;
}
