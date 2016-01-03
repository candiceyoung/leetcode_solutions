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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        if (head->next == NULL) return head;
        if (m == n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = head;
        ListNode *pre = dummy;
        ListNode *before = dummy;
        int counter = 0;
        while (current) {
            counter++;
            if (counter < m) {
                pre = current;
                current = current->next;
            }
            else if (counter == m) {
                before = current;
                current = current->next;
            }
            else if (counter > m && counter <= n) {
                ListNode *tmp1 = pre->next;
                ListNode *tmp2 = current->next;
                pre->next = current;
                current->next = tmp1;
                before->next = tmp2;
                current = tmp2;
            }
            else break;
        }
        return dummy->next;
    }
};