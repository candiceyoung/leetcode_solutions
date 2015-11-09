#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void re_combine(vector<int>& temp, int i, int k, int n) {
        if (k == temp.size()) {
            ans.push_back(temp);
        }
        for (int j = i; j <= n; ++j) {
            temp.push_back(j);
            re_combine(temp, j + 1, k, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        re_combine(temp, 1, k, n);
        return ans;
    }
private:
    vector<vector<int>> ans;
};

int main(void) {
    vector<vector<int>> result;
    Solution s;
    result = s.combine(5, 3);
    int row_num = result.size();
    int col_num = result[0].size();
    for (int i = 0; i < row_num; ++i) {
        for (int j = 0; j < col_num; ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
