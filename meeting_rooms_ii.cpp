/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Node {
public:
    int val;
    int type;
    Node(int v, int t) : val(v), type(t) {}
};
class Solution {
public:
    static bool less(Node *a, Node *b) {
        if (a->val == b->val) return a->type < b->type;
        else return a->val < b->val;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int size = intervals.size();
        if (size == 0) return 0;
        vector<Node*> v;
        for (int i = 0; i < intervals.size(); ++i) {
            Node* s = new Node(intervals[i].start, 1);
            Node* e = new Node(intervals[i].end, 0);
            v.push_back(s);
            v.push_back(e);
        }
        sort(v.begin(), v.end(), less);
        int maximum = 0, temp_max = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i]->type == 1) temp_max++;
            else temp_max--;
            maximum = max(maximum, temp_max);
        }
        return maximum;
    }
};