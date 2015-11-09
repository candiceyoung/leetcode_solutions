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
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head->next->next->next;
        ListNode* dummy = head;
        head->next = dummy->next->next;
        head->next->next = dummy->next;
        dummy->next->next = temp;
        temp = swapPairs(temp);
        return head;
    }
};
int main(void) {
    Solution s;
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);
    ListNode *head;
    head->next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    ListNode *result = s.swapPairs(head);
    while (result) {
        cout << result->val << "    ";
        result = result->next;
    }
    /*
    while (result->next) {
        cout << result->next->val << "    ";
        result = result->next;
    }
    */
    cout << endl;
    return 0;
}
