/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        int temp = (head->val == INT_MIN) ? 0 : (head->val - 1);
        ListNode *dummy = new ListNode(temp);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        int former = dummy->val;
        pre->next = NULL;
        while (cur) {
            if (cur->next && cur->next->val == cur->val) {
                former = cur->val;
                cur = cur->next;
            }
            else if (cur->val == former) {
                cur = cur->next;
            }
            else {
                former = cur->val;
                pre->next = cur;
                pre = pre->next;
                cur = cur->next;
                pre->next = NULL;
            }
        }
        return dummy->next;
    }
};