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
    void inorder(TreeNode* root, vector<int> &result, vector<int> &temp) {
        if (!root) return;
        inorder(root->left, result, temp);
        temp.push_back(root->val);
        result.push_back(root->val);
        inorder(root->right, result, temp);
    }
    void modify(TreeNode* root, int target1, int target2) {
        if (!root) return;
        modify(root->left, target1, target2);
        if (root->val == target1) root->val = target2;
        else if (root->val == target2) root->val = target1;
        modify(root->right, target1, target2);
    }
    void recoverTree(TreeNode* root) {
        if (!root) return;
        vector<int> result, temp;
        inorder(root, result, temp);
        sort(temp.begin(), temp.end());
        int target1, target2;
        for (int i = 0; i < result.size(); ++i) {
            if (temp[i] != result[i]) {
                target1 = temp[i];
                target2 = result[i];
            }
        }
        modify(root, target1, target2);
    }
};

/*
class Solution {
private:
    TreeNode *first, *second;
    TreeNode *pre;
public:
    Solution() {
        first = NULL;
        second = NULL;
        pre = new TreeNode(INT_MIN);
    }
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        if (!first && pre->val >= root->val) first = pre;
        if (first && pre->val >= root->val) second = root;
        pre = root;
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
        if (!root) return;
        traverse(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
*/
