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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> value;
            for (int i = 0; i < size; ++i) {
                TreeNode *temp = q.front();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                value.push_back(temp->val);
                q.pop();
            }
            result.push_back(value);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main(void) {
    return 0;
}
