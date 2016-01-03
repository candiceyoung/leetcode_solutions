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
        if (head->next == NULL) return head;
        int temp = (head->val == INT_MIN) ? 0 : (head->val - 1);
        ListNode *dummy = new ListNode(temp);
        dummy->next = head;
        int former = dummy->val;
        ListNode *current = head;
        ListNode *pre = dummy;
        int flag = 0;
        while (current) {
            if (current->next && current->val == current->next->val) {
                former = current->val;
                current = current->next;
            }
            else if (current->val == former) {
                former = current->val;
                current = current->next;
                flag = 0;
            }
            else {
                former = current->val;
                pre->next = current;
                pre = current;
                current = current->next;
                flag = 1;
            }
        }
        if (!flag) {
            pre->next = current;
        }
        return dummy->next;
    }
};