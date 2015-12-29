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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return NULL;
        if (!root->left) return root;
        TreeNode *new_root;
        new_root = upsideDownBinaryTree(root->left);
        TreeNode *cur_left = root->left;
        TreeNode *cur_right = root->right;
        cur_left->right = root;
        cur_left->left = cur_right;
        root->left = NULL;
        root->right = NULL;
        return new_root;
    }
};