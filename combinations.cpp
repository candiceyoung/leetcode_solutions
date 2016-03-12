class Solution {
public:
    void recursive(vector<vector<int>> &result, vector<int> &temp, int start, int &k, int &n) {
        if (k == temp.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i <= n; ++i) {
            temp.push_back(i);
            recursive(result, temp, i + 1, k, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        recursive(result, temp, 1, k, n);
        return result;
    }
};