#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        int length = 1;
        int pos = 1;
        int value = nums[0];
        int dup = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == value) {
                if (dup < 2) {
                    dup++;
                    int temp = nums[i];
                    nums[i] = nums[pos];
                    nums[pos] = temp;
                    pos++;
                    length++;
                }
            }
            else {
                dup = 1;
                value = nums[i];
                int temp = nums[i];
                nums[i] = nums[pos];
                nums[pos] = temp;
                pos++;
                length++;
            }
        }
        return length;
    }
};
int main(void) {
    vector<int> nums = {1, 1, 1, 2, 3, 3, 4, 4, 4, 4, 5};
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
    return 0;
}
