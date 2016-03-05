#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> before;
        vector<int> row1 = {1};
        vector<int> row2 = {1, 1};
        if (rowIndex == 0) return row1;
        if (rowIndex == 1) return row2;
        before = row2;
        for (int i = 2; i <= rowIndex; ++i) {
            vector<int> after;
            after.push_back(1);
            for (int j = 0; j < before.size() - 1; ++j) {
                after.push_back(before[j] + before[j + 1]);
            }
            after.push_back(1);
            before = after;
        }
        return before;
    }
};
int main(void) {
    Solution s;
    vector<int> result = s.getRow(3);
    for (int i = 0; i < result.size(); ++i) cout << result[i] << "  ";
    cout << endl;
    return 0;
}

/*
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex + 1);
        for (int i = 0; i < rowIndex + 1; ++i) {
            result[i].resize(i + 1);
            result[i][0] = 1;
            result[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }
        return result[rowIndex];
    }
};
*/
