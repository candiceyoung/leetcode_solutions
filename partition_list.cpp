#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *head1, *head2;
        head1 = dummy1;
        head2 = dummy2;
        while (head) {
            if (head->val < x) {
                head1->next = head;
                head1 = head1->next;
            }
            else {
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
        }
        head2->next = NULL;
        head1->next = dummy2->next;
        return dummy1->next;
    }
};
int main(void) {
    Solution s;
    ListNode *head = NULL;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(1);
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    ListNode *result = s.partition(head, 3);
    while (result) {
        cout << result->val << "    ";
        result = result->next;
    }
    cout << endl;
}   
