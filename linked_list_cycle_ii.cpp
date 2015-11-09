#include <iostream>
#include <map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return NULL;
        map<ListNode *, int> rmap;
        ListNode *nextNode = head;
        rmap[head] = 0;
        while (nextNode->next) {
            nextNode = nextNode->next;
            if (rmap.find(nextNode) == rmap.end()) {
                // not found
                rmap[nextNode] = 1;
            }
            else {
                return nextNode;
            }
        }
        return NULL;
    }
};
int main(void) {
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);
    ListNode node6 = ListNode(6);
    ListNode node7 = NULL;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node3;

    ListNode node11 = ListNode(1);
    ListNode node21 = ListNode(2);
    ListNode node31 = ListNode(3);
    node11.next = &node21;
    node21.next = &node31;
    node31.next = NULL;
    ListNode *head = &node11;
    Solution s;
    ListNode *result = s.detectCycle(head);
    if (result) cout << result->val << endl;
    else cout << "haha" << endl;
    return 0;
}
