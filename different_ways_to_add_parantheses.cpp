#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> recPar(string input, int i, int j) {
        vector<int> result;
        int flag = 0;
        for (int k = i; k <= j; ++k) {
            if (input[k] == '+' || input[k] == '-' || input[k] == '*') {
                flag = 1;
                vector<int> left = recPar(input, i, k - 1);
                vector<int> right = recPar(input, k + 1, j);
                for (int m = 0; m < left.size(); ++m) {
                    for (int n = 0; n < right.size(); ++n) {
                        if (input[k] == '+') result.push_back(left[m] + right[n]);
                        if (input[k] == '-') result.push_back(left[m] - right[n]);
                        if (input[k] == '*') result.push_back(left[m] * right[n]);
                    }
                }
            }
        }
        if (flag == 0) {
            int val = 0;
            for (int t = i; t <= j; ++t) {
                val = val * 10 + (int)(input[t] - '0');
            }
            result.push_back(val);
            return result;            
        }
        return result;
    }
    vector<int> diffWaysToCompute(string input) {
        return recPar(input, 0, input.size() - 1);
    }
};
int main(void) {
    string input = "10+2*3-31*555";
    Solution s;
    vector<int> result = s.diffWaysToCompute(input);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
