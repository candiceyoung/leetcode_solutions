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
    TreeNode* recursive(vector<int>& inorder, vector<int>& postorder, int start1, int end1, int start2, int end2) {
        if (start1 > end1 || start2 > end2) return NULL;
        TreeNode *root = new TreeNode(postorder[end2]);
        int rootIndex = -1;
        for (int i = start1; i <= end1; ++i) {
            if (inorder[i] == root->val) rootIndex = i;
        }
        if (rootIndex == -1) return NULL;
        int leftsize = rootIndex - start1;
        int rightsize = end1 - rootIndex;
        root -> left = recursive(inorder, postorder, start1, rootIndex - 1, start2, start2 + leftsize - 1);
        root -> right = recursive(inorder, postorder, rootIndex + 1, end1, end2 - rightsize, end2 - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;
        return recursive(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
int main(void) {
    return 0;
}
