#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> counter;
        vector<int>::iterator it;
        for (it = nums.begin(); it < nums.end(); ++it) {
            if (counter.find(*it) != counter.end()) {
                counter[*it]++;
            }
            else counter[*it] = 1;
        }
        map<int, int>::iterator mit;
        for (mit = counter.begin(); mit != counter.end(); ++mit) {
            if ((*mit).second != 3) return (*mit).first;
        }
        return 0;
    }
};
int main(void) {
    Solution s;
    vector<int> vec = {1, 2, 1, 3, 1, 3, 2, 2};
    cout << s.singleNumber(vec) << endl;
    vector<int> vec1 = {1, 1};
    cout << s.singleNumber(vec1) << endl;
    return 0;
}
