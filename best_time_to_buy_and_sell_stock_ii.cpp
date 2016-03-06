class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0) return 0;
        int max_profit = 0;
        int start = prices[0], end = prices[0];
        for (int i = 1; i < size; ++i) {
            if (prices[i] < end) {
                if (start < end) max_profit += (end - start);
                start = prices[i];
                end = prices[i];
            }
            else {
                end = prices[i];
            }
        }
        if (end > start) max_profit += (end - start);
        return max_profit;
    }
};