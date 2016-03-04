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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = head;
        head = head->next;
        while (head) {
            if (head->val != pre->val) {
                pre = head;
                head = head->next;
                continue;
            }
            else {
                head = head->next;
                pre->next = head;
            }
        }
        return dummy->next;
    }
};