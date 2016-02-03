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
    void reorderList(ListNode *head) {
        // write your code here
        if (!head || !head->next) return;
        ListNode *current = head;
        int total = 0;
        while (current) {
            total++;
            current = current->next;
        }
        int half = total / 2;
        // reverse part of the list
        ListNode *pre = head;
        current = head->next;
        int number = 1;
        while (number < total - half) {
            current = current->next;
            pre = pre->next;
            number++;
        }
        while (current->next) {
            ListNode *current_next_next = current->next->next;
            ListNode *pre_next = pre->next;
            pre->next = current->next;
            current->next->next = pre_next;
            current->next = current_next_next;
        }
        
        current = head;
        ListNode *brk = pre;
        pre = pre->next;
        brk->next = NULL;
        
        while (pre) {
            ListNode *pre_next = pre->next;
            ListNode *current_next = current->next;
            current->next = pre;
            pre->next = current_next;
            pre = pre_next;
            current = current->next->next;
        }
    }
};