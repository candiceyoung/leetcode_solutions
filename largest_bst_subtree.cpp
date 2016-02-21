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
    bool isBST(TreeNode *root) {
        return check(root, NULL, NULL);
    }
    bool check(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (!root) return true;
        if ((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
        return check(root->left, min, root) && check(root->right, root, max);
    }
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        int num = 0;
        if (isBST(root)) return largestBSTSubtree(root->left) + 1 + largestBSTSubtree(root->right);
        else return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};