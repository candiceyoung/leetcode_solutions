#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode * temp = s.top();
            result.push_back(temp->val);
            s.pop();
            if (temp->right) s.push(temp->right);
            if (temp->left) s.push(temp->left);
        }
        return result;
    }
};
int main(void) {
    return 0;
}
