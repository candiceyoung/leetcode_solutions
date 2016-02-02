class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    static bool myComparison(const string a, const string b) {
        string s1 = a + b;
        string s2 = b + a;
        return s1 > s2; 
    }
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> num_str(num.size(), "");
        for (int i = 0; i < num.size(); ++i) {
            num_str[i] = to_string(num[i]);
        }
        sort(num_str.begin(), num_str.end(), myComparison);
        string result = "";
        for (int i = 0; i < num_str.size(); ++i) {
            result += num_str[i];
        }
        return (result[0] == '0') ? "0" : result;
    }
};