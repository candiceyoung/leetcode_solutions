#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void dfs(vector<string> &result, TreeNode *root, string temp) {
        if (!root->left && !root->right) {
            result.push_back(temp);
            return;
        }
        if (root->left) dfs(result, root->left, temp + "->" + to_string(root->left->val));
        if (root->right) dfs(result, root->right, temp + "->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;

        dfs(result, root, to_string(root->val));
        return result;
    }
};
int main(void) {
    return 0;
}
