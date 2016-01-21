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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                dummy->next = cur1;
                cur1 = cur1->next;
                dummy = dummy->next;
                dummy->next = NULL;
            }
            else if (cur1->val > cur2->val) {
                dummy->next = cur2;
                cur2 = cur2->next;
                dummy = dummy->next;
                dummy->next = NULL;
            }
        }
        if (cur1) dummy->next = cur1;
        else if (cur2) dummy->next = cur2;
        return head->next;
    }
};