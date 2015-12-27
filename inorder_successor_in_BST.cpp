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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode *>s;
        TreeNode *pNode;
        pNode = root;
        bool found = false;
        while (pNode || !s.empty()) {
            if (pNode) {
                s.push(pNode);
                pNode = pNode->left;
            }
            else {
                pNode = s.top();
                s.pop();
                if (found) return pNode;
                if (pNode == p) found = true;
                pNode = pNode->right;
            }
        }
    }
};