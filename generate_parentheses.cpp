#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void recGP(int left_n, int right_n, string s, int n, vector<string> &result) {
        if (left_n > n) return;
        if (left_n == n && right_n == n) result.push_back(s);
        else {
            recGP(left_n + 1, right_n, s + '(', n, result);
            if (left_n > right_n) recGP(left_n, right_n + 1, s + ')', n, result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        recGP(0, 0, "", n, result);
        return result;
    }
};
int main(void) {
    vector<string>::iterator it;
    Solution s;
    vector<string> result = s.generateParenthesis(5);
    for (it = result.begin(); it != result.end(); ++it) {
        cout << *it << "    ";
    }
    cout << endl;
    cout << result.size() << endl;
    return 0;
}

/*
class Solution {
public:
    void recursive(int left, int right, vector<string> &result, string &temp, int n) {
        if (temp.length() == 2 * n && left == n && right == n) {
            result.push_back(temp);
            return;
        }
        if (left > right) {
            if (left + 1 <= n) {
                temp += '(';
                recursive(left + 1, right, result, temp, n);
                temp.pop_back();
            }
            if (right + 1 <= n) {
                temp += ')';
                recursive(left, right + 1, result, temp, n);
                temp.pop_back();
            }
        }
        else if (left == right) {
            if (left + 1 <= n) {
                temp += '(';
                recursive(left + 1, right, result, temp, n);
                temp.pop_back();
            }
        }
        else return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        string temp = "";
        recursive(0, 0, result, temp, n);
        return result;
    }
};
*/
