#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        int result = 0;
        for (int i = 1; i < height.size(); ++i) {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], height[i + 1]);
        }
        for (int i = 0; i < height.size(); ++i) {
            if ((min(left[i], right[i]) - height[i]) > 0) {
                result += min(left[i], right[i]) - height[i];
            }
        }
        return result;
    }
};
int main(void) {
    Solution s;
    vector<int> height = {0, 9, 3, 1, 5, 10};
    cout << s.trap(height) << endl;
    return 0;
}

/*
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size == 0) return 0;
        int left = 0, right = size - 1;
        int maximum = 0;
        int left_max = 0, right_max = 0;
        while (left <= right) {
            left_max = max((int)height[left], left_max);
            right_max = max((int)height[right], right_max);
            if (left_max < right_max) {
                maximum += (left_max - height[left]);
                left++;
            }
            else {
                maximum += (right_max - height[right]);
                right--;
            }
        }
        return maximum;
    }
};
*/
