class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        if (len == 0) return 0;
        int sign = 1, i = 0;
        while (str[i] == ' ') i++;
        if (str[i] == '+') i++;
        else if (str[i] == '-') {sign = -1; i++;}
        long long result = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + str[i++] - '0';
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            else if (sign == -1 && -result < INT_MIN) return INT_MIN;
        }
        return sign * result;
    }
};