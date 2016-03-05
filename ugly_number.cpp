class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
        if (num == 1 || num == 2 || num == 3 || num == 5) return true;
        if ((num % 2 == 0) && isUgly(num / 2)) return true;
        else if ((num % 3 == 0) && isUgly(num / 3)) return true;
        else if ((num % 5 == 0) && isUgly(num / 5)) return true;
        return false;
    }
};