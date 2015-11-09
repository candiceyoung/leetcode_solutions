#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int> > vec(m, vector<int>(n, 1));
        vector< vector<int> >::iterator row_it;
        vector<int>::iterator col_it;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
            }
        }
        return vec[m - 1][n - 1];
    }
};
int main(void) {
    Solution s;
    cout << s.uniquePaths(3, 3) << endl;
    return 0;
}
