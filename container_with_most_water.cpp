#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(currentArea, maxArea);
            if (height[left] > height[right]) right--;
            else if (height[left] < height[right]) left++;
            else {right--; left++;}
        }
        return maxArea;
    }
};
int main(void) {
    vector<int> height = {3, 5, 2, 8};
    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}
