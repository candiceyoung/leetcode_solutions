#include <iostream>
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
    void flatten(TreeNode* root) {
        stack<TreeNode *> st;
        if (root == NULL) return;
        st.push(root);
        TreeNode *temp = root;
        while (!st.empty()) {
            TreeNode *current = st.top();
            st.pop();
            if (current->right) st.push(current->right);
            if (current->left) st.push(current->left);
            if (current != root) {
                temp->right = current;
                temp->left = NULL;
                temp = temp->right;
            } 
        }
    }
};
