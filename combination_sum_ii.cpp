#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void combination(vector<vector<int>> &result, int start, int target, vector<int> &temp, vector<int> &candidates) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int j = start; j < candidates.size(); ++j) {
            if (j != 0 && candidates[j] == candidates[j - 1] && j > start) continue;
            if (candidates[j] > target) break;
            temp.push_back(candidates[j]);
            combination(result, j + 1, target - candidates[j], temp, candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        if (candidates.size() == 0) return result;
        sort(candidates.begin(), candidates.end());
        combination(result, 0, target, temp, candidates);
        return result;
    }
};
int main(void) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates1 = {2, 2, 2};
    Solution s;
    vector<vector<int>> result = s.combinationSum2(candidates1, 4);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
