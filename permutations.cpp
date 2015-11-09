#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void generatePermute(vector<int> &nums, int i, vector<vector<int> > &result) {
        if (i >= nums.size()) {
            result.push_back(nums);
            return;
        }
        // swap
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[j], nums[i]);
            generatePermute(nums, i+1, result);
            swap(nums[j], nums[i]);
        }
    }
    vector<vector<int> > permute(vector<int> &nums) {
        vector<vector<int> > result;
        generatePermute(nums, 0, result);
        return result;
    }
};
int main(void) {
    Solution s;
    vector<int> input = {1, 2, 3, 4};
    vector<vector<int>> result = s.permute(input);
    vector<vector<int>>::iterator it1;
    vector<int>::iterator it2;
    for (it1 = result.begin(); it1 != result.end(); ++it1) {
        for (it2 = it1->begin(); it2 != it1->end(); ++it2) {
            cout << *it2 << "   ";
        }
        cout << endl;
    }
    return 0;
}
