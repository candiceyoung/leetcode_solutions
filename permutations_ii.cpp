#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    void generatePermute(vector<int> &nums, int i, vector<vector<int>> &result) {
        if (i >= nums.size()) {
            result.push_back(nums);
            return;
        }
        int j = i;
        set<int> visited;
        while (j < nums.size()) {
            if (visited.find(nums[j]) != visited.end()) {
                j++;
                continue;
            }
            swap(nums[j], nums[i]);
            generatePermute(nums, i + 1, result);
            swap(nums[j], nums[i]);
            visited.insert(nums[j++]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        generatePermute(nums, 0, result);
        return result;
    }
};
int main(void) {
    Solution s;
    vector<int> input = {1, 1, 2, 3};
    vector<vector<int>> result = s.permuteUnique(input);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
