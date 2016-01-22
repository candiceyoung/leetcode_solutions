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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0); 
        ListNode *head = dummy;
        int carry = 0;
        while (l1 && l2) {
            int r = l1->val + l2->val + carry;
            if (r > 9) {
                ListNode * n = new ListNode(r - 10);
                head->next = n;
                carry = 1;
            }
            else {
                ListNode *n = new ListNode(r);
                head->next = n;
                carry = 0;
            }
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) {
            while (l1) {
                int r = l1->val + carry;
                if (r > 9) {
                    ListNode *n = new ListNode(r - 10);
                    head->next = n;
                    carry = 1;
                }
                else {
                    ListNode *n = new ListNode(r);
                    head->next = n;
                    carry = 0;
                }
                head = head->next;
                l1 = l1->next;
            }  
        }
        else if (l2) {
            while (l2) {
                int r = l2->val + carry;
                if (r > 9) {
                    ListNode *n = new ListNode(r - 10);
                    head->next = n;
                    carry = 1;
                }
                else {
                    ListNode *n = new ListNode(r);
                    head->next = n;
                    carry = 0;
                }
                head = head->next;
                l2 = l2->next;
            }  
        }
        if (carry == 1) {
            ListNode *n = new ListNode(1);
            head->next = n;
        }
        return dummy->next;
    }
};

/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *dummy = &preHead;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            dummy->next = new ListNode(sum % 10);
            dummy = dummy->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};
*/