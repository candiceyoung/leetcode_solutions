#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> flag_vector;
        vector<int>::iterator it;
        int max = 0, length = 0, missing_number = 0;
        for (it = nums.begin(); it < nums.end(); ++it) {
            if (*it > max) max = *it;
            flag_vector.push_back(0);
            length++;
        }
        flag_vector.push_back(0);
        length++;
        for (it = nums.begin(); it < nums.end(); ++it) {
            flag_vector.at(*it) = 1;
        }
        for (int i = 0; i < length; ++i) {
            if (flag_vector.at(i) == 0) missing_number = i;
        }
        if (max == 0) return 1;
        else return missing_number;
    }
};
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = (0 + size) * (size + 1) / 2;
        for (int i = 0; i < size; ++i) {
            sum -= nums[i];
        }
        return sum;
    }
};
*/
int main() {
    vector<int> ivec = {1, 0};
    Solution s;
    cout << s.missingNumber(ivec) << endl;
    return 0;
}
