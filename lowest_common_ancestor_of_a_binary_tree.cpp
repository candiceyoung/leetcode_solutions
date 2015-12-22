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
    void route(int found, vector<TreeNode *> &temp, vector<vector<TreeNode *>> &result, TreeNode* root, TreeNode* target1, TreeNode* target2) {
        if (found > 2) return;
        if (!root) return;
        temp.push_back(root);
        if (target1 == root || target2 == root) {
            result.push_back(temp);
            found++;
        }
        if (root->left) route(found, temp, result, root->left, target1, target2);
        if (root->right) route(found, temp, result, root->right, target1, target2);
        temp.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> temp;
        vector<vector<TreeNode*>> routes;
        route(0, temp, routes, root, p, q);
        TreeNode* result;
        if ((routes.size() != 2) ||((routes.size() == 2) && (routes[0].size() == 0)) || ((routes.size() == 2) && (routes[1].size() == 0))) return result;
        int i = 0;
        while (routes[0][i] == routes[1][i]) {
            i++;
        }
        result = routes[0][i - 1];
        return result;
    }
};
int main(void) {
    return 0;
}
