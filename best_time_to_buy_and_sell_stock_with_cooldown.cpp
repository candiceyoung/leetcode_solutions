#include <iostream>
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) return 0;
        vector<int> profit;
        profit.push_back(0);
        for (int i = 1; i < prices.size(); ++i) {
            int max = INT_MIN;
            int temp;
            int local_max;
            for (int j = i - 1; j >= 0; --j) {
                temp = 0;
                if (prices[i] > prices[j]) temp = prices[i] - prices[j];
                if (j > 2) temp += profit[j - 2];
                local_max = (temp > profit[i - 1]) ? temp : profit[i - 1];
                if (local_max > max) max = local_max;
            }
            profit.push_back(max);
        }
        if (profit[prices.size() - 1] == INT_MIN) return 0;
        else return profit[prices.size() - 1];
    }
};
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0) return 0;
        vector<int> B(size, 0);
        vector<int> S(size, 0);
        vector<int> C(size, 0);
        B[0] = -prices[0];
        int maximum = 0;
        for (int i = 1; i < size; ++i) {
            B[i] = max(C[i - 1] - prices[i], B[i - 1]);
            S[i] = max(B[i - 1] + prices[i], S[i - 1]);
            C[i] = S[i - 1];
            maximum = max(maximum, max(B[i], max(S[i], C[i])));
        }
        return maximum;
    }
};
*/
int main(void) {
    vector<int> prices = {1, 2, 3, 0, 2};
    vector<int> prices1 = {5, 3, 4, 8, 15, 2};
    Solution s;
    cout << s.maxProfit(prices1) << endl;
    return 0;
}
