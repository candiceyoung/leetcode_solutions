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
    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1) return true;
        return false;
    }
};
int main(void) {
	return 0;
}