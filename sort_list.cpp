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
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (!head) return head;
        vector<int> nums;
        ListNode *current = head;
        while (current) {
            nums.push_back(current->val);
            current = current->next;
        }
        sort(nums.begin(), nums.end());
        current = head;
        int i = 0;
        while (current) {
            current->val = nums[i];
            i++;
            current = current->next;
        }
        return head;
    }
};