#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    static bool early(const Interval &i1, const Interval &i2) {
        return i1.start < i2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {

        vector<Interval> result;
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), early);

        int end = intervals[0].end, start = intervals[0].start;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start > end) {
                Interval temp = Interval(start, end);
                result.push_back(temp);
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else if (intervals[i].end > end) {
                end = intervals[i].end;
            }
        }
        Interval last = Interval(start, end);
        result.push_back(last);
        return result;
    }
};
int main(void) {
    return 0;
}
