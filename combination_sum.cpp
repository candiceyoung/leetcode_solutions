#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void combination(vector<vector<int>> &result, vector<int> &candidates, int start, int target, vector<int> &temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int j = start; j < candidates.size(); ++j) {
            if (target < candidates[j]) break;
            for (int i = 1; i <= target/candidates[j]; ++i) {
                int k;
                for (k = 0; k < i; ++k) {
                    temp.push_back(candidates[j]);
                }
                combination(result, candidates, j+1, target - candidates[j] * k, temp);
                for (k = 0; k < i; ++k) {
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combination(result, candidates, 0, target, temp);
        return result;
    }
};
int main(void) {
    vector<int> candidates = {2, 3, 6, 7};
    Solution s;
    vector<vector<int>> result = s.combinationSum(candidates, 9);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
