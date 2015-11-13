#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        if (obstacleGrid[0][0] == 1) return 0;
        bool flag = false;
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (!flag) {
                if (obstacleGrid[i][0] == 1) {
                    flag = true;
                    obstacleGrid[i][0] = 0;
                }
                else obstacleGrid[i][0] = 1;
            }
            else obstacleGrid[i][0] = 0;
        }
        flag = false;
        for (int i = 1; i < obstacleGrid[0].size(); ++i) {
            if (!flag) {
                if (obstacleGrid[0][i] == 1) {
                    flag = true;
                    obstacleGrid[0][i] = 0;
                }
                else obstacleGrid[0][i] = 1;
            }
            else obstacleGrid[0][i] = 0;
        }
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
int main(void) {
    return 0;
}
