class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if (denominator == 0) return result;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
            result += '-';
        }
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator <0 ? (long)denominator * (-1) : (long)denominator;
        unordered_map<int, int> mp;
        result += to_string(numer / denom);
        result += ".";
        numer = numer % denom;
        int i = result.length();
        while (numer) {
            i++;
            if (mp.find(numer) != mp.end()) {
                result = result.substr(0, mp[numer] - 1) + "(" + result.substr(mp[numer] - 1, i - mp[numer]) + ")";
                break;
            }
            else {
                mp[numer] = i;
                result += to_string(numer * 10 / denom);
                numer = numer * 10 % denom;
            }
        }
        int len = result.length();
        if (result[len - 1] == '.') result = result.substr(0, len - 1);
        return result;
    }
};