class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        unordered_map<int, vector<int>> ma, mb;
        vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                if (A[i][j] != 0) {
                    ma[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < B.size(); ++i) {
            for (int j = 0; j < B[i].size(); ++j) {
                if (B[i][j] != 0) {
                    mb[i].push_back(j);
                }
            }
        }
        unordered_map<int, vector<int>>::iterator it;
        for (it = ma.begin(); it != ma.end(); ++it) {
            if (mb.find(it->first) != mb.end()) {
                // found
                vector<int> a1 = it->second;
                vector<int> a2 = mb[it->first];
                for (int i = 0; i < a1.size(); ++i) {
                    for (int j = 0; j < a2.size(); ++j) {
                        // cout << a1[i] << ", " << a2[j] << endl;
                        result[a1[i]][a2[j]] += A[a1[i]][it->first] * B[it->first][a2[j]];
                    }
                }
            }
        }
        return result;
    }
};