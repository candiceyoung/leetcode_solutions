#include <iostream>
#include <cstdint>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) + (n >> i & 1);
        }
        return result;
    }
};
int main(void) {
    uint32_t num = 12;
    Solution s;
    cout << s.reverseBits(num) << endl;
    return 0;
}
