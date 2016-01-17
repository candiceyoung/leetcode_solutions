class Solution {
public:
    void recursive(vector<string> &result, vector<char> &nums1, vector<char> &nums2, string start, int n) {
        if (n == 0) {
            if (start.length() > 1 && start[0] == '0') return;
            result.push_back(start);
            return;
        }
        for (int i = 0; i < nums1.size(); ++i) {
            recursive(result, nums1, nums2, nums1[i] + start + nums2[i], n - 2);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        vector<char> nums1 = {'0', '1', '6', '8', '9'};
        vector<char> nums2 = {'0', '1', '9', '8', '6'};
        vector<string> result;
        if (n % 2 == 0) {
            recursive(result, nums1, nums2, "", n);
        }
        else {
            recursive(result, nums1, nums2, "0", n - 1);
            recursive(result, nums1, nums2, "1", n - 1);
            recursive(result, nums1, nums2, "8", n - 1);
        }
        return result;
    }
};
/*
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
*/