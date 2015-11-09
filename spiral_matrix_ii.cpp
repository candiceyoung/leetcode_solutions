#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n, 0));
        if (n == 0) return result;
        int x = 0, y = 0;
        int i = 1;
        result[0][0] = i++;
        while (i <= n*n) {
            // keep going right
            while (y+1 < n && result[x][y+1] == 0) {
                result[x][++y] = i++;
            }
            // keep going down
            while(x+1 < n && result[x+1][y] == 0) {
                result[++x][y] = i++;
            }
            // keep going left
            while(y-1 >= 0 && result[x][y-1] == 0) {
                result[x][--y] = i++;
            }
            // keep going up
            while (x-1 >= 0 && result[x-1][y] == 0) {
                result[--x][y] = i++;
            }
        }
        return result;
    }
};
int main(void) {
    Solution s;
    vector<vector<int>> result = s.generateMatrix(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << result[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}
