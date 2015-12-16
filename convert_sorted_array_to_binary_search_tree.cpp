#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* recursive(int low, int high, vector<int>& nums) {
        if (low > high) return NULL;
        int mid = low + (high - low) / 2;
        TreeNode *middle = new TreeNode(nums[mid]);
        middle -> left = recursive(low, mid - 1, nums);
        middle -> right = recursive(mid + 1, high, nums);
        return middle;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(0, nums.size() - 1, nums);
    }
};
int main(void) {
    return 0;
}
