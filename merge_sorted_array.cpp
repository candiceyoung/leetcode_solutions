#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        m--;
        n--;
        // for (int j = 0; j < n; ++j) nums1.push_back(0);
        while (m >= 0 && n >= 0) {
            nums1[i--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while (n >= 0) {
            nums1[i--] = nums2[n--];
        }
    }
};
int main(void) {
    vector<int> arr1 = {1, 3, 8};
    vector<int> arr2 = {4, 5, 7, 10, 11};
    Solution s;
    s.merge(arr1, 3, arr2, 5);
    for (int i = 0; i < arr1.size(); ++i) {
        cout << arr1[i] << "    ";
    }
    cout << endl;
    return 0;
}
