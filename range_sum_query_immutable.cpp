#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            
            sum.push_back(sum[i] + nums[i]);
        }
    }
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
private:
    vector<int> sum;
};
int main(void) {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(2, 5) << endl;
    return 0;
}
