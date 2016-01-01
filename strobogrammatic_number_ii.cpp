class Solution {
public:
    vector<string> recursive(int n) {
        vector<string> result;
        if (n == 1) {
            result.push_back(to_string(0));
            result.push_back(to_string(1));
            result.push_back(to_string(8));
        }
        if (n == 2) {
            result.push_back("00");
            result.push_back("11");
            result.push_back("88");
            result.push_back("69");
            result.push_back("96");
        }
        if (n > 2) {
            vector<string> v2 = recursive(n - 2);
            for (int i = 0; i < v2.size(); ++i) {
                result.push_back(to_string(6) + v2[i] + to_string(9));
                result.push_back(to_string(9) + v2[i] + to_string(6));
                result.push_back(to_string(1) + v2[i] + to_string(1));
                result.push_back(to_string(8) + v2[i] + to_string(8));
                result.push_back(to_string(0) + v2[i] + to_string(0));
            }
        }
        return result;
    }
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        if (n == 1) {
            result.push_back(to_string(0));
            result.push_back(to_string(1));
            result.push_back(to_string(8));
            return result;
        }
        if (n == 2) {
            result.push_back("11");
            result.push_back("88");
            result.push_back("69");
            result.push_back("96");
            return result;
        }
        if (n > 2) {
            vector<string> v2 = recursive(n - 2);
            for (int i = 0; i < v2.size(); ++i) {
                result.push_back(to_string(6) + v2[i] + to_string(9));
                result.push_back(to_string(9) + v2[i] + to_string(6));
                result.push_back(to_string(1) + v2[i] + to_string(1));
                result.push_back(to_string(8) + v2[i] + to_string(8));
            }
        }
        return result;
        
    }
};