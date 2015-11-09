#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>::iterator it;
        int m = INT_MIN;
        int sum = 0;
        for (it = nums.begin(); it != nums.end(); ++it) {
            sum = sum >= 0 ? (sum + *it) : (*it);
            m = max(sum, m);
        }
        return m;
    }
};
int main(void) {
    Solution s;
    vector<int> vec = {1, 2};
    cout << s.maxSubArray(vec) << endl;
    return 0;
}
