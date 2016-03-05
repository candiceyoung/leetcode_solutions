#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> before;
        // vector<int> after;
        vector<int> row1 = {1};
        vector<int> row2 = {1, 1};
        if (numRows == 0) return result;
        if (numRows == 1) {
            result.push_back(row1);
            return result;
        }
        if (numRows == 2) {
            result.push_back(row1);
            result.push_back(row2);
            return result;
        }
        result.push_back(row1);
        result.push_back(row2);
        before = row2;
        for (int i = 2; i < numRows; ++i) {
            vector<int> after;
            after.push_back(1);
            for (int j = 0; j < before.size() - 1; ++j) {
                after.push_back(before[j] + before[j + 1]);
            }
            after.push_back(1);
            result.push_back(after);
            before = after;
        }
        return result;
    }
};
int main(void) {
    Solution s;
    vector<vector<int>> result = s.generate(5);
    return 0;
}
/*

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; ++i) {
            result[i].resize(i + 1);
            result[i][0] = 1;
            result[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }
        return result;
    }
};

*/
