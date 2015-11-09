#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if ((root->left == NULL) && (root->right == NULL) && ((sum - root->val) == 0)) return true;
        return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};
int main(void) {
    TreeNode t1 = TreeNode(5);
    TreeNode t2 = TreeNode(4);
    TreeNode t3 = TreeNode(11);
    TreeNode t4 = TreeNode(7);
    TreeNode t5 = TreeNode(2);
    TreeNode t6 = TreeNode(8);
    TreeNode t7 = TreeNode(13);
    TreeNode t8 = TreeNode(4);
    TreeNode t9 = TreeNode(1);
    t1.left = &t2;
    t1.right = &t6;
    t2.left = &t3;
    t3.left = &t4;
    t3.right = &t5;
    t6.left = &t7;
    t6.right = &t8;
    t8.right = &t9;
    Solution s;
    cout << s.hasPathSum(&t1, 21) << endl;
    return 0;
}
