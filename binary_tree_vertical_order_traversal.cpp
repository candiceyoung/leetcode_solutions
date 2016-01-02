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
    void recursive(TreeNode *root, int col, unordered_map<TreeNode *, int> &m) {
        m[root] = col;
        if (root->left) recursive(root->left, col - 1, m);
        if (root->right) recursive(root->right, col + 1, m);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        unordered_map<TreeNode *, int> m;
        unordered_map<int, vector<int>> m1;
        recursive(root, 0, m);
        // level order traversal
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *temp = q.front();
                if (m1[m[temp]].size() == 0) m1[m[temp]].push_back(m[temp]);
                m1[m[temp]].push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                q.pop();
            }
        }
        unordered_map<int, vector<int>>::iterator it;
        for (it = m1.begin(); it != m1.end(); ++it) {
            result.push_back(it->second);
        }
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i) {
            result[i].erase(result[i].begin());
        }
        return result;
    }
};