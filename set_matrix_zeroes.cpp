// O(1) space: store the state in the first element in the row and col
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col;
        set<int> row;
        set<int>::iterator it;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (row.find(i) == row.end()) row.insert(i);
                    if (col.find(j) == col.end()) col.insert(j);
                }
            }
        }
        for (it = row.begin(); it != row.end(); ++it) {
            for (int i = 0; i < matrix[0].size(); ++i) {
                matrix[*it][i] = 0;
            }
        }
        for (it = col.begin(); it != col.end(); ++it) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][*it] = 0;
            }
        }
    }
};
int main(void) {
    vector<vector<int>> matrix = {{5, 8, 3, 0, 1, 4}, {2, 0, 6, 1, 1, 1}, {2, 3, 4, 5, 6, 6}};
    Solution s;
    s.setZeroes(matrix);
    cout << matrix[0][0] << endl;
    return 0;
}
