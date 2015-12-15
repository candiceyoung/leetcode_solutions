#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        for (int max_num = 0; i < size && i <= max_num; ++i) {
            max_num = max(i + nums[i], max_num);
        }
        return i == size;
    }
};
int main(void) {
    vector<int> nums = {0, 4, 3};
    Solution s;
    cout << s.canJump(nums) << endl;
    return 0;
}
