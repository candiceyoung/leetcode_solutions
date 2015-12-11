#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void combination(vector<vector<int>> &result, int cur, int start, int target, vector<int> &temp, int k) {
        if (target == 0 && cur == k) {
            result.push_back(temp);
            return;
        }
        for (int j = start; j < 10; ++j) {
            if (j > target) break;
            temp.push_back(j);
            combination(result, cur + 1, j + 1, target - j, temp, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k == 0 && n == 0) return result;
        if (k * 9 < n) return result;
        vector<int> temp;
        combination(result, 0, 1, n, temp, k);
        return result;
    }
};
int main(void) {
    Solution s;
    vector<vector<int>> result;
    result = s.combinationSum3(3, 9);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
