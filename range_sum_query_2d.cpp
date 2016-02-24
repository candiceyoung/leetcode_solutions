#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> middleSum;
    int sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if (row == 0) {
            sum = 0;
            return;
        }
        int col = matrix[0].size();
        middleSum.resize(row, vector<int>(col, 0));
        middleSum[0][0] = matrix[0][0];
        for (int i = 1; i < col; ++i) {
            middleSum[0][i] = middleSum[0][i - 1] + matrix[0][i];
        }
        for (int i = 1; i < row; ++i) {
            middleSum[i][0] = middleSum[i - 1][0] + matrix[i][0];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                middleSum[i][j] = middleSum[i][j - 1] + middleSum[i - 1][j] - middleSum[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > 0 && col1 > 0 && row2 > 0 && col2 > 0) return middleSum[row2][col2] - middleSum[row2][col1 - 1] - middleSum[row1 - 1][col2] + middleSum[row1 - 1][col1 - 1];
        else if (row1 == 0 && col1 == 0) return middleSum[row2][col2];
        else if (row1 == 0 && col1 != 0) return middleSum[row2][col2] - middleSum[row2][col1 - 1];
        else if (row1 != 0 && col1 == 0) return middleSum[row2][col2] - middleSum[row1 - 1][col2];
    }
};

int main(void) {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    return 0;
}
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);