#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int i = 0;
        while (!q.empty()) {
            i++;
            int size = q.size();
            for (int j = 0; j < size; ++j) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left == NULL && node->right == NULL) return i;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
        }
        return i;
    }
};
int main(void) {
    TreeNode *n1 = new TreeNode(1);
    Solution s;
    cout << s.minDepth(n1) << endl;
    return 0;
}

/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
*/
