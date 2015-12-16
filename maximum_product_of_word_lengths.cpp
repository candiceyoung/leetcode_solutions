#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string> &words) {
         unordered_map<int, int> m;
         for (int i = 0; i < words.size(); ++i) {
            int ans = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                ans = (1 << (int)(words[i][j] - 'a')) | ans;       
            }
            if (m.find(ans) == m.end()) m[ans] = words[i].length();
            else {
                if (words[i].length() > m[ans]) m[ans] = words[i].length();
            }
         }
         int max = 0;
         for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            for (unordered_map<int, int>::iterator it1 = it; it1 != m.end(); it1++) {
                if (it->first & it1->first) continue;
                else if (it->second * it1->second > max) {
                    max = it->second * it1->second;
                }
            }
         }
         return max;
    }
};
int main(void) {
    vector<string> words = {"bdcecbcadca","caafd","bcadc","eaedfcd","fcdecf","dee","bfedd","ffafd","eceaffa","caabe","fbdb","acafbccaa","cdc","ecfdebaafde","cddbabf","adc","cccce","cbbe","beedf","fafbfdcb","ceecfabedbd","aadbedeaf","cffdcfde","fbbdfdccce","ccada","fb","fa","ec","dddafded","accdda","acaad","ba","dabe","cdfcaa","caadfedd","dcdcab","fadbabace","edfdb","dbaaffdfa","efdffceeeb","aefdf","fbadcfcc","dcaeddd","baeb","beddeed","fbfdffa","eecacbbd","fcde","fcdb","eac","aceffea","ebabfffdaab","eedbd","fdeed","aeb","fbb","ad","bcafdabfbdc","cfcdf","deadfed","acdadbdcdb","fcbdbeeb","cbeb","acbcafca","abbcbcbaef","aadcafddf","bd","edcebadec","cdcbabbdacc","adabaea","dcebf","ffacdaeaeeb","afedfcadbb","aecccdfbaff","dfcfda","febb","bfffcaa","dffdbcbeacf","cfa","eedeadfafd","fcaa","addbcad","eeaaa","af","fafc","bedbbbdfae","adfecadcabe","efffdaa","bafbcbcbe","fcafabcc","ec","dbddd","edfaeabecee","fcbedad","abcddfbc","afdafb","afe","cdad","abdffbc","dbdbebdbb"};
    Solution s;
    cout << s.maxProduct(words) << endl;
    return 0;
}
