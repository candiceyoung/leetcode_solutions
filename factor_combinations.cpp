class Solution {
public:
    void recursive(vector<vector<int>> &result, vector<int> &temp, int min, int n) {
        for (int i = min; i < n; ++i) {
            if (n % i == 0 && i <= (n / i)) {
                temp.push_back(i);
                temp.push_back(n / i);
                result.push_back(temp);
                temp.pop_back();
                recursive(result, temp, i, n / i);
                temp.pop_back();
            }
            if (i > (n / i)) break;
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        if (n == 1) return result;
        vector<int> temp;
        recursive(result, temp, 2, n);
        return result;
    }
};