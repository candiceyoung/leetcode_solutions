#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        if (headA == NULL || headB == NULL) return NULL;
        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1 -> next;
            p2 = p2 -> next;
            if (p1 == p2) return p1;
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }
        return p1;
    }
};
int main(void) {
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *b1 = new ListNode(4);
    ListNode *b2 = new ListNode(5);
    ListNode *b3 = new ListNode(6);
    ListNode *b4 = new ListNode(7);
    a1->next = a2;
    a2->next = a3;
    b1->next = b2;
    b2->next = b3;
    b3->next = b4;
    Solution s;
    ListNode *result = s.getIntersectionNode(a1, b1);
    if (!result) cout << "hehe" << endl;
    else cout << result->val << endl;
    return 0;
}
