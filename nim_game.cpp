#include <iostream>
using namespace std;
class Solution {
    public:
        bool canWinNim(int n) {
            if (n % 4 == 0) return false;
            else return true;
        }
};
int main(void) {
    Solution s;
    cout << s.canWinNim(12) << endl;
    cout << s.canWinNim(10) << endl;
    return 0;
}
