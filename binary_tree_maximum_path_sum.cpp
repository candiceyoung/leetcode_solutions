/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxToRoot(TreeNode *root, int &maxSum) {
        if (!root) return 0;
        int left_max = max(0, maxToRoot(root->left, maxSum));
        int right_max = max(0, maxToRoot(root->right, maxSum));
        maxSum = max(maxSum, left_max + right_max + root->val);
        return root->val + max(left_max, right_max);
    }
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        maxToRoot(root, max);
        return max;
    }
};