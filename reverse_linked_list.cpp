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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        if (!head || head->next == NULL) return head;
        ListNode *pre = head;
        ListNode *current = head->next;
        while (current) {
            ListNode *dummy_next = dummy->next;
            ListNode *current_next = current->next;
            dummy->next = current;
            current->next = dummy_next;
            pre->next = current_next;
            current = current_next;
        }
        return dummy->next;
    }
};