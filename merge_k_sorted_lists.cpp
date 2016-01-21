#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = new ListNode(0);
        ListNode *head = result;
        auto my_comp = [](ListNode *node1, ListNode *node2) {return node1->val > node2->val;};
        priority_queue<ListNode *, vector<ListNode *>, decltype(my_comp)> queue(my_comp);
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) queue.push(lists[i]);
        }
        while(queue.empty() != true) {
            ListNode * smallest = queue.top();
            queue.pop();
            result->next = smallest;
            result = result->next;
            if (smallest->next) queue.push(smallest->next);
            
        }
        return head->next;
    }
};
int main(void) {
    return 0;
}

/*
class myComparison {
public:
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        priority_queue<ListNode*, vector<ListNode*>, myComparison> record;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) record.push(lists[i]);
        }
        while (!record.empty()) {
            ListNode *smallest = record.top();
            record.pop();
            dummy->next = smallest;
            dummy = dummy->next;
            if (smallest->next) record.push(smallest->next);
        }
        return head->next;
    }
};
*/
