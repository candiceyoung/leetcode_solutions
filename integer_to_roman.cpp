#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        map<int, string> code {
            {1, "I"},
            {2, "II"},
            {3, "III"},
            {4, "IV"},
            {5, "V"},
            {6, "VI"},
            {7, "VII"},
            {8, "VIII"},
            {9, "IX"},
            {10, "X"},
            {20, "XX"},
            {30, "XXX"},
            {40, "XL"},
            {50, "L"},
            {60, "LX"},
            {70, "LXX"},
            {80, "LXXX"},
            {90, "XC"},
            {100, "C"},
            {200, "CC"},
            {300, "CCC"},
            {400, "CD"},
            {500, "D"},
            {600, "DC"},
            {700, "DCC"},
            {800, "DCCC"},
            {900, "CM"},
            {1000, "M"},
            {2000, "MM"},
            {3000, "MMM"},
        };
        int units = 0, tens = 0, hundreds = 0, thousands = 0;
        int number = 0, bits = 0;
        while (num) {
            number = num % 10;
            bits++;
            num = num / 10;
            if (bits == 1) units = number;
            else if(bits == 2) tens = number * 10;
            else if (bits == 3) hundreds = number * 100;
            else if (bits == 4) thousands = number * 1000; 
        }
        if (thousands) result += code.find(thousands)->second;
        if (hundreds) result += code.find(hundreds)->second;
        if(tens) result += code.find(tens)->second;
        if(units) result += code.find(units)->second;
        return result;
    }
};
int main(void) {
    Solution s;
    cout << s.intToRoman(3333) << endl;
    return 0;
}
