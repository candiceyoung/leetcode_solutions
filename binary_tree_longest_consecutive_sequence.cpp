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
    void recursive(TreeNode* root, int &max, int &cur_max) {
        if (!root) return;
        int temp = cur_max;
        if (root->left) {
            if (root->left->val == root->val + 1) {
                cur_max++;
                if (cur_max > max) max = cur_max;
            }
            else cur_max = 1;
            recursive(root->left, max, cur_max);
            cur_max = temp;
        }
        if (root->right) {
            if (root->right->val == root->val + 1) {
                cur_max++;
                if (cur_max > max) max = cur_max;
            }
            else cur_max = 1;
            recursive(root->right, max, cur_max);
            cur_max = temp;
        }
    }
    int longestConsecutive(TreeNode* root) {
        int max = 1, cur_max = 1;
        if (!root) return 0;
        recursive(root, max, cur_max);
        return max;
    }
};