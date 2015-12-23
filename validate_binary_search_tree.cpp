#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return check(root, NULL, NULL);
    }
    bool check(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (!root) return true;
        if ((min && root->val <= min->val) ||(max && root->val >= max->val)) return false;
        return check(root->left, min, root) && check(root->right, root, max);
    }
};
int main(void) {
    cout << INT_MIN << ", " << INT_MAX<< endl;
    return 0;
}
