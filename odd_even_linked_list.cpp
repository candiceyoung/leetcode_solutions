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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_dummy = new ListNode(0);
        ListNode *even_dummy = new ListNode(0);
        ListNode *odd_current = odd_dummy;
        ListNode *even_current = even_dummy;
        int i = 0;
        if (!head) return head;
        while (head) {
            i++;
            if (i % 2) {
                // odd
                odd_current->next = head;
                head = head->next;
                odd_current = odd_current->next;
                odd_current->next = NULL;
            }
            else {
                // even
                even_current->next = head;
                head = head->next;
                even_current = even_current->next;
                even_current->next = NULL;
            }
        }
        if (even_dummy->next) odd_current->next = even_dummy->next;
        return odd_dummy->next;
    }
};