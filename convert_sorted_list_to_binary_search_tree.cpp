#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* recursive(int start, int end, vector<int> &nums) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *middle = new TreeNode(nums[mid]);
        middle -> left = recursive(start, mid - 1, nums);
        middle -> right = recursive(mid + 1, end, nums);
        return middle;
    }
    TreeNode* sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        vector<int> array;
        while (head) {
            array.push_back(head->val);
            head = head->next;
        }
        return recursive(0, array.size() - 1, array);
    }
};
int main(void) {
    return 0;
}
