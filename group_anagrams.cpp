#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 0) return result;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (m.find(tmp) != m.end()) {
                m[tmp].push_back(strs[i]);
            }
            else {
                m[tmp].push_back(strs[i]);
            }
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            result.push_back(it->second);
        }
        return result;
    }
};
int main(void) {
    return 0;
}
