#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> forward;
            vector<int> backward;
            vector<int> result;
            vector<int>::iterator it;
            if (nums.size() == 0) {
                result.push_back(0);
                return result;
            }
            int temp = 1;
            forward.push_back(temp);
            for (it = nums.begin()+1; it < nums.end(); ++it) {
                temp *= *(it - 1);
                forward.push_back(temp);
            }
            temp = 1;
            backward.push_back(temp);
            for (it = nums.end() - 2; it >= nums.begin(); --it) {
                temp *= *(it + 1);
                backward.push_back(temp);
            }
            vector<int>::iterator begin, end;
            for (begin = forward.begin(), end = backward.end() - 1; begin < forward.end(), end >= backward.begin(); ++begin, --end) {
                result.push_back((*begin) * (*end));
            }
            return result;
        }
};
int main(void) {
    Solution s;
    vector<int> vec = {0, 0};
    vector<int> result;
    vector<int>::iterator it;
    result = s.productExceptSelf(vec);
    for (it = result.begin(); it < result.end(); ++it) {
        cout << *it << "    ";
    }
    cout << endl;
    return 0;
}
