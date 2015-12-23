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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *p;
        p = root;
        vector<int> result;
        if (!root) return result;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p -> left;
            }
            else {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p -> right;
            }
        }
        return result;
    }
};
int main(void) {
    return 0;
}
