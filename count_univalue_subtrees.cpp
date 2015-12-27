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
    bool isValid(TreeNode* root, int &count) {
        if (!root) return true;
        if (root->left == NULL && root->right == NULL) {
            count++;
            return true;
        }
        bool leftValid = isValid(root->left, count);
        bool rightValid = isValid(root->right, count);
        if ( leftValid && rightValid) {
            if (root->left && root->right && root->left->val == root->right->val && root->left->val == root->val) {
                count++;
                return true;
            }
            if (root->left && root->right == NULL && root->left->val == root->val) {
                count++;
                return true;
            }
            if (root->left == NULL && root->right && root->right->val == root->val) {
                count++;
                return true;
            }
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        isValid(root, count);
        return count;
    }
};