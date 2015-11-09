// the answer is reverse
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> re_combine(int i, int k, int n) {
        vector<vector<int>> result;
        if (k == 1) {
            for (int j = i; j <= n; ++j) {
                vector<int> temp;
                temp.push_back(j);
                result.push_back(temp);
            }
            return result;
        }
        for (int j = i; j <= n - k + 1; ++j) {
            vector<vector<int>> temp;
            temp = re_combine(j + 1, k - 1, n);
            vector<vector<int>>::iterator it;
            for (it = temp.begin(); it != temp.end(); ++it) {
                (*it).push_back(j);
                result.push_back(*it);
            }
        }
        return result;
    }
    vector<vector<int>> combine(int n, int k) {
        return re_combine(1, k, n);
    }
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
