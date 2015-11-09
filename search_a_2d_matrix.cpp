#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
int main(void) {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 12, 22}, {10, 13, 14, 17, 24}, {18, 21, 24, 26, 30}};
    Solution s;
    cout << s.searchMatrix(matrix, 5) << endl;
    cout << s.searchMatrix(matrix, 20) << endl;
    return 0;
}
