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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        TreeNode *pNode;
        pNode = root;
        int num = 0;
        vector<int> result;
        while (!s.empty() || pNode) {
            if (pNode) {
                s.push(pNode);
                pNode = (*pNode).left;
            }
            else {
                pNode = s.top();
                s.pop();
                result.push_back((*pNode).val);
                num++;
                if (num == k) return (*pNode).val;
                pNode = (*pNode).right;
            }
        }
        return 0;
    }
};
int main(void) {
    return 0;
}
