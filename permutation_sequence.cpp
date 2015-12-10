#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        if (n == 1) {
            result.push_back(char(1 + '0'));
            return result;
        }
        vector<int> nums;
        int factor = 1;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
            factor *= i;
        }
        k = k - 1;
        while (k) {
            factor = factor / n;
            int no = k / factor;
            k = k % factor;
            n = n - 1;
            result.push_back(char(nums[no] + '0'));
            nums.erase(nums.begin() + no);
        }
        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(char(nums[i] + '0'));
        }
        return result;
    }
};
int main(void) {
    Solution s;
    cout << s.getPermutation(3, 1) << endl;
    return 0;
}
