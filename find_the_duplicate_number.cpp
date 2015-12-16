#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mid) count++;
            }
            if (count > mid) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
int main(void) {
    return 0;
}
