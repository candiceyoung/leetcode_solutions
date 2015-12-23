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
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((p && !q) || (q && !p)) return false;
        if (p->val == q->val) return check(p->left, q->right) && check(p->right, q->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
};
int main(void) {
    return 0;
}
