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
/*
class Solution {
public:
    vector<int> singleNumber(vector<int> &A) {
        // write your code here
        vector<int> result;
        int size = A.size();
        if (size == 0) return result;
        set<int> st;
        for (int i = 0; i < size; ++i) {
            if (st.find(A[i]) == st.end()) st.insert(A[i]);
            else st.erase(A[i]);
        }
        for (set<int>::iterator it = st.begin(); it != st.end(); ++it) {
            result.push_back(*it);
        }
        return result;
    }
};
*/
/*
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};
*/
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
