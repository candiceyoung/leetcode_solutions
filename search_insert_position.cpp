#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator it;
        int position = 0;
        for (it = nums.begin(); it < nums.end(); ++it) {
            if (target == *it) {
                return position;
            }
            else if (target < *it) {
                return position;
            }
            else {
                position++;
            }
        }
        return position;
    }
};
int main(void) {
    Solution s;
    vector<int> vec = {1, 3, 5, 9};
    cout << s.searchInsert(vec, 5) << endl;
    cout << s.searchInsert(vec, 6) << endl;
    cout << s.searchInsert(vec, 10) << endl;
    vector<int> ivec = {1};
    cout << s.searchInsert(ivec, 0) << endl;
    vector<int> ivec1 = {0};
    cout << s.searchInsert(ivec1, 1) << endl;
    return 0;
}
