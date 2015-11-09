#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
int main(void) {
    vector<vector<int> > vec(3, vector<int>(3));
    vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(vec);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
