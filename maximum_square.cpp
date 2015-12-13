#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int max = INT_MIN;
        vector<vector<int>> maxMap(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == '1') { maxMap[i][0] = 1; max = 1; }
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == '1') { maxMap[0][i] = 1; max = 1; }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '0') maxMap[i][j] = 0;
                else {
                    int a = maxMap[i][j - 1];
                    int b = maxMap[i - 1][j - 1];
                    int c = maxMap[i - 1][j];
                    int temp = (a < b) ? a : b;
                    temp = (c < temp) ? c : temp;
                    maxMap[i][j] = temp + 1;
                    if (maxMap[i][j] > max) max = maxMap[i][j];
                }
            }
        }
        return max * max;
    }
};
int main(void) {
}
