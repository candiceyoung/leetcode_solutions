#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int>::iterator it;
        int result = nums[0];
        for (it = nums.end() - 1; it > nums.begin(); --it) {
            if (*it < *(it - 1)) result = *it;
        }
        return result;
    }
};
int main(void) {
    vector<int> vec = {4, 5, 1, 2, 3};
    Solution s;
    cout << s.findMin(vec) << endl;
    return 0;
}
