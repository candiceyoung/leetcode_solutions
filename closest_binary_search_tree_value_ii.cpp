/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// inorder
class Solution {
public:
    void inorderTraversal(TreeNode *root, vector<TreeNode *> &inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root);
        inorderTraversal(root->right, inorder);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> result;
        if (!root) return result;
        vector<TreeNode *> inorder;
        inorderTraversal(root, inorder);
        
        int pos = 0, total = 0;
        while (pos < inorder.size() && (double)inorder[pos]->val <= target) pos++;
        
        int i = pos - 1, j = pos;
        while (i >= 0 && j < inorder.size() && total < k) {
            if (target - (double)(inorder[i]->val) < (double)(inorder[j]->val) - target) {
                result.push_back(inorder[i--]->val);
                total++;
            }
            else {
                result.push_back(inorder[j++]->val);
                total++;
            }
        }
        if (total == k) return result;
        else if (i < 0) {
            while (total < k && j < inorder.size()) {
                result.push_back(inorder[j++]->val);
                total++;
            }
            return result;
        }
        else if (j >= inorder.size()) {
            while (total < k && i >= 0) {
                result.push_back(inorder[i--]->val);
                total++;
            }
            return result;
        }
        return result;
    }
};