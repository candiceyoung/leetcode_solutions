class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int row = image.size();
        if (row == 0) return 0;
        int col = image[0].size();
        int left = col, right = -1, up = row, down = -1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (image[i][j] == '1') {
                    if (i < up) up = i;
                    if (i > down) down = i;
                    if (j < left) left = j;
                    if (j > right) right = j;
                }
            }
        }
        return (right - left + 1) * (down - up + 1);
    }
};