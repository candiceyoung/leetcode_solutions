#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
    public:
        vector<int> SingleNumber(vector<int>& nums) {
            vector<int> result;
            map<int, int> kv;
            vector<int>::iterator it;
            for (it = nums.begin(); it < nums.end(); ++it) {
                if (kv.find(*it) == kv.end()) {
                    kv[*it] = 1;
                }
                else kv[*it] += 1;
            }
            map<int, int>::iterator map_it;
            for (map_it = kv.begin(); map_it != kv.end(); ++map_it) {
                if (map_it->second == 1) result.push_back(map_it->first);
            }
            return result;
        }
};
int main(void) {
    Solution s;
    vector<int> vec = {1, 2, 1, 3, 2, 5};
    vector<int> result;
    result = s.SingleNumber(vec);
    vector<int>::iterator it;
    for (it = result.begin(); it < result.end(); ++it) {
        cout << *it << "    ";
    }
    cout << endl;
    return 0;
}
