#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        if (!root) return result;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                temp.push_back(node -> val);
                q.pop();
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            result.push_back(temp);
        }
        for (int i = 0; i < result.size(); ++i) {
            if (i % 2) {
                reverse(result[i].begin(), result[i].end());
            }
        }
        return result;
    }
};
int main(void) {
    return 0;
}
