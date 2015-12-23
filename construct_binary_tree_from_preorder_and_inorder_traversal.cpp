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
    TreeNode* recursive(vector<int>& preorder, vector<int>& inorder, int start1, int end1, int start2, int end2) {
        if (start1 > end1 || start2 > end2) return NULL;
        TreeNode *root = new TreeNode(preorder[start1]);
        int rootIndex = -1;
        for (int i = start2; i <= end2; ++i) {
            if (inorder[i] == root->val) rootIndex = i;
        }
        if (rootIndex == -1) return NULL;
        int leftsize = rootIndex - start2;
        int rightsize = end2 - rootIndex;
        root -> left = recursive(preorder, inorder, start1 + 1, start1 + leftsize, start2, rootIndex - 1);
        root -> right = recursive(preorder, inorder, end1 + 1 - rightsize, end1, rootIndex + 1, end2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        return recursive(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
int main(void) {
    return 0;
}
