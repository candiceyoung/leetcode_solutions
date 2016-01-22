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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        if (!head || head->next == NULL || k == 1) return head;
        int i = 1;
        ListNode *pre = head;
        ListNode *current = head->next;
        ListNode *start = dummy;
        while (current) {
            if (i % k == 0) {
                start = pre;
                pre = current;
                i++;
                current = current->next;
            }
            if (!current) break;
            ListNode *current_next = current->next;
            ListNode *start_next = start->next;
            start->next = current;
            current->next = start_next;
            pre->next = current_next;
            current = current_next;
            i++;
        }
        if (i % k != 0) {
            current = start->next;
            if (current->next == NULL) return dummy->next;
            pre = current;
            current = current->next;
            while (current) {
                ListNode *start_next = start->next;
                ListNode *current_next = current->next;
                start->next = current;
                current->next = start_next;
                pre->next = current_next;
                current = current_next;
            }
        }
        return dummy->next;
    }
};