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
    vector<TreeNode*> recursive(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            vector<TreeNode*> null(1, NULL);
            return null;
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left_set = recursive(start, i - 1);
            vector<TreeNode*> right_set = recursive(i + 1, end);
            for (int j = 0; j < left_set.size(); ++j) {
                for (int k = 0; k < right_set.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = left_set[j];
                    root -> right = right_set[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> null;
            return null;
        }
        return recursive(1, n);
    }
};
int main(void) {
    return 0;
}
