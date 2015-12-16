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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        if (!head) return head;
        ListNode *dummy = head;
        ListNode *tail;
        while (dummy -> next) {
            len++;
            dummy = dummy -> next;
        }
        len++;
        if (len == 1 || k % len == 0) return head;
        tail = dummy;
        int move = 0;
        dummy = head;
        while (move < (len - k % len - 1)) {
            dummy = dummy -> next;
            move++;
        }
        ListNode *result = dummy -> next;
        tail -> next = head;
        dummy ->next = NULL;
        return result;
    }
};
int main(void) {
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    ListNode *head = &node1;

    Solution s;
    ListNode *result = s.rotateRight(head, 3);
    while (result) {
        cout << result -> val << endl;
        result = result -> next;
    }
    return 0;
}
