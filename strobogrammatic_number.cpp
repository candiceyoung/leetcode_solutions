class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.length();
        for (int i = 0; i <= len / 2; ++i) {
            if (num[i] != '0' && num[i] != '1' && num[i] != '6' && num[i] != '8' && num[i] != '9') {
                return false;
            }
            if (num[i] == '6') {
                if (num[len - 1 - i] != '9') return false;
            }
            else if (num[i] == '9') {
                if (num[len - 1 - i] != '6') return false;
            }
            else {
                if (num[len - 1 - i] != num[i]) return false;
            }
        }
        return true;
    }
};