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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p;
        while(true) {
            if (p->next == NULL || p->next->next == NULL) break;
            ListNode* q1 = p->next;
            ListNode* q2 = q1->next;
            q1->next = q2->next;
            q2->next = q1;
            p->next = q2;
            p = q1;
        }
        return head->next;
    }
};
int main(void) {
    Solution s;
    ListNode *head = NULL;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    ListNode *result = s.swapPairs(head);
    while (result) {
        cout << result->val << "    ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
