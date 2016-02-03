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
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        while (head) {
            ListNode *dummy_next = dummy->next;
            ListNode *head_next = head->next;
            dummy->next = head;
            head->next = dummy_next;
            head = head_next;
        }
        return dummy->next;
    }
};
/* recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        if (!head || head->next == NULL) return head;
        ListNode *after = reverseList(head->next);
        dummy->next = after;
        head->next->next = head;
        head->next = NULL;
        return dummy->next;
    }
};
*/