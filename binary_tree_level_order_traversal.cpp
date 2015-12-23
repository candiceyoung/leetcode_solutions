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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode *> thisLevel, nextLevel;
        vector<vector<int>> result;
        if (!root) return result;
        thisLevel.push_back(root);
        while (thisLevel.size()) {
            vector<int> value;
            for (int i = 0; i < thisLevel.size(); ++i) {
                if (thisLevel[i]->left) nextLevel.push_back(thisLevel[i]->left);
                if (thisLevel[i]->right) nextLevel.push_back(thisLevel[i]->right);
                value.push_back(thisLevel[i]->val);
            }
            result.push_back(value);
            thisLevel = nextLevel;
            nextLevel.clear();
        }
        return result;
    }
};
int main(void) {
    return 0;
}
