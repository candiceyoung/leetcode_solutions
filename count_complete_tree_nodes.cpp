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
    int height(TreeNode *root) {
        int height = 0;
        while (root) {
            height++;
            root = root -> left;
        }
        return height;
    }
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int count = 1;
        int l_height = height(root->left);
        int r_height = height(root->right);
        if (l_height == r_height + 1) {
            count = count + countNodes(root->left) + pow(2, r_height) - 1;
        }
        else if (l_height == r_height) {
            count = count + pow(2, l_height) - 1 + countNodes(root->right);
        }
        return count;
    }
};
int main(void) {
    return 0;
}
