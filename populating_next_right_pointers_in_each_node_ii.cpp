/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> q;
        if (!root) return;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            TreeLinkNode *temp = q.front();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            q.pop();
            for (int i = 1; i < size; ++i) {
                TreeLinkNode *next = q.front();
                q.pop();
                temp->next = next;
                temp = next;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            temp->next = NULL;
        }
    }
};
int main(void) {
    return 0;
}