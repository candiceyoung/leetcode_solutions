 #include <iostream>
 #include <stack>
 using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    void recursionSum(TreeNode* root, int currSum, int &sum) {
        if (!root) return;
        currSum = currSum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) sum += currSum;
        if (root->left) recursionSum(root->left, currSum, sum);
        if (root->right) recursionSum(root->right, currSum, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        recursionSum(root, 0, sum);
        return sum;
    }
};
