class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        string result;
        if (len == 0) return result;
        if (numRows == 1) return s;
        vector<vector<char>> zz(numRows);
        int row = 0;
        bool direction = false;
        int total = 0, index = 0;
        while (index < len) {
            total++;
            if (total % numRows == 1) {
                direction = !direction;
                if (direction) row = 0;
                else row = numRows - 1;
            }
            if (total % numRows == 1 && !direction) {
                zz[row--].push_back(' ');
            }
            else if (total % numRows == 0 && !direction) {
                zz[row].push_back(' ');
            }
            else {
                zz[row].push_back(s[index++]);
                if (direction) row++;
                else row--;
            }
        }
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < zz[i].size(); ++j) {
                if (zz[i][j] == ' ') continue;
                else result += zz[i][j];
            }
        }
        return result;
    }
};