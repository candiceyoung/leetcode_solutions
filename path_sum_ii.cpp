#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void recursive(TreeNode* root, int sum, vector<vector<int>> &result, vector<int> &temp) {
        if (!root) return;
        temp.push_back(root->val);
        if ((sum == root->val) && (root->left == NULL) && (root->right == NULL)) {
            result.push_back(temp);
        }
        recursive(root->left, sum - root->val, result, temp);
        recursive(root->right, sum - root->val, result, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> temp;
        recursive(root, sum, result, temp);
        return result;
    }
};
int main(void) {
    return 0;
}
