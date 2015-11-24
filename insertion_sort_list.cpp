#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = head->next;
        dummy->next->next = NULL;
        while (head) {
            ListNode *cur = dummy;
            while (cur->next && cur->next->val < head->val) cur = cur->next;
            if (cur->next == NULL) {
                ListNode *temp = head->next;
                cur->next = head;
                cur->next->next = NULL;
                head = temp;
            }
            else {
                ListNode *tmp = cur->next;
                cur->next = head;
                head = head->next;
                cur->next->next = tmp;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
int main(void) {
    ListNode *head = NULL;
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(5);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(6);
    ListNode *node6 = new ListNode(3);
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    Solution s;
    ListNode *result = s.insertionSortList(head);
    while (result) {
        cout << result->val << "    ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
