class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for (int price : prices) {
            release2 = max(release2, hold2 + price);
            hold2 = max(hold2, release1- price);
            release1 = max(release1, hold1 + price);
            hold1 = max(hold1, -price);
        }
        return release2;
    }
};