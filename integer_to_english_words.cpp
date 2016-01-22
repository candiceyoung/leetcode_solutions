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