#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> delta;
        for (int i = 0; i < gas.size(); ++i) {
            delta.push_back(gas[i] - cost[i]);
        }
        int sum = 0, total_delta = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += delta[i];
            total_delta += delta[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        if (total_delta < 0) return -1;
        else return start;
    }
};
int main(void) {
    return 0;
}
