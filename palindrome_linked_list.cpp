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
    bool isPalindrome(ListNode* head) {
        vector<int> result;
        ListNode *p = head;
        while (p) {
            result.push_back(p->val);
            p = p->next;
        }
        int size = result.size();
        for (int i = 0; i < size / 2; ++i) {
            if (result[i] != result[size - 1 - i]) return false;
        }
        return true;
    }
};