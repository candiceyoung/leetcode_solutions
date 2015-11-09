#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        if (matrix.size() == 1) return matrix[0];
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        vector<vector<int>> visited(row_num, vector<int>(col_num, 0));
        int x = 0, y = 0;
        int i = 1;
        result.push_back(matrix[0][0]);
        visited[0][0] = 1;
        while (i < row_num*col_num) {
            // keep going right
            while (y+1 < col_num && visited[x][y+1] == 0) {
                result.push_back(matrix[x][++y]);
                visited[x][y] = 1;
                i++;
            }
            cout << i << endl;
            // keep going down
            while (x+1 < row_num && visited[x+1][y] == 0) {
                result.push_back(matrix[++x][y]);
                visited[x][y] = 1;
                i++;
            }
            cout << i << endl;
            // keep going left
            while (y-1 >= 0 && visited[x][y-1] == 0) {
                result.push_back(matrix[x][--y]);
                visited[x][y] = 1;
                i++;
            }
            cout << i << endl;
            // keep going up
            while(x-1 >= 0 && visited[x-1][y] == 0) {
                result.push_back(matrix[--x][y]);
                visited[x][y] = 1;
                i++;
            }
            cout << i << endl;
        }
        return result;
    }
};
int main(void) {
    Solution s;
    vector<vector<int> > matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << "  ";
    }
    cout << endl;
}
