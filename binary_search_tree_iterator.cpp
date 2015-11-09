#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty()) return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = st.top();
        st.pop();
        if (top->right != NULL) find_left(top->right);
        return top->val;
    }
    /** put all the left child node into stack */
    void find_left(TreeNode* root) {
        TreeNode* p = root;
        while (p != NULL) {
            st.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
