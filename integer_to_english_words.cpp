class Solution {
private:
    vector<string> digits = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
public:
    string intToString(int n) {
        if (n >= 1000000000) {
            return intToString(n / 1000000000) + " Billion" + intToString(n % 1000000000);
        }
        else if (n >= 1000000) {
            return intToString(n / 1000000) + " Million" + intToString(n % 1000000);
        }
        else if (n >= 1000) {
            return intToString(n / 1000) + " Thousand" + intToString(n % 1000);
        }
        else if (n >= 100) {
            return intToString(n / 100) + " Hundred" + intToString(n % 100);
        }
        else if (n >= 20) {
            return " " + tens[n / 10] + intToString(n % 10);
        }
        else if (n >= 1) {
            return " " + digits[n];
        }
        else return "";
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result = intToString(num);
        return result.substr(1);
    }
};

/*
string readThousand(int input) {
    assert(input < 1000);
    string res;
    vector<string> digitToStr = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
    vector<string> teensToStr = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    vector<string> tysToStr = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    int hun = input / 100;
    if (hun >= 1) res += digitToStr[hun] + " Hundred";
    input %= 100;
    int tens = input / 10;
    input %= 10;
//    cout << "input here is " << input << endl;
    if (tens == 1) {res += teensToStr[input]; return res; }
    if (tens > 1) res += tysToStr[tens];
    res += digitToStr[input];
    return res;
}
string numberToWords(int num) {
    vector<int> parts(4, 0);
    string res;
    vector<string> thous = {"", " Thousand", " Million", " Billion"};
    for (int i = 0; i < 4; i++) {
        parts[i] = num % 1000;
        if (parts[i] > 0) res = readThousand(parts[i]) + thous[i] + res;
        num /= 1000;
        if (num == 0) break;
    }
    if (res.empty()) return "Zero";
    return res.substr(1);
}
*/