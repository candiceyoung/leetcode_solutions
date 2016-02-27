class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int size = x.size();
        if (size < 4) return false;
        for (int i = 3; i < size; ++i) {
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) { cout << i << endl; return true; }
            if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) { cout << i << endl; return true; }
            if (i >= 5 && x[i] + x[i - 4] >= x[i - 2] && x[i - 2] >= x[i - 4] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i - 3] >= x[i - 1]) { cout << i << endl; return true; }
        }
        return false;
    }
};