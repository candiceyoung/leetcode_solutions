#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next && slow) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow && fast == slow) return true;
        }
        return false;
    }
};
int main(void) {
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);
    ListNode node6 = ListNode(6);
    ListNode node7 = ListNode(7);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = NULL;
    ListNode *head = &node1;

    Solution s;
    cout << s.hasCycle(head) << endl;
    return 0;
}
