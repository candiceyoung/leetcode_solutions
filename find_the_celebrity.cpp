#include <iostream>
#include <vector>
using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b) {
    if (a == 0 && b == 1) return false;
    else return true;
}

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                if (knows(j, i) == false) break;
                else count++;
            }
            if (count == (n - 1)) v.push_back(i);
        }
        int size = v.size(); 
        if (size == 0) return -1;
        for (int i = 0; i < size; ++i) {
            int flag = 0;
            for (int j = 0; j < n; ++j) {
                if (j == v[i]) continue;
                if (knows(v[i], j)) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) return v[i];
        }
        return -1;
    }
};
int main(void) {
    Solution s;
    cout << s.findCelebrity(2) << endl;
    return 0;
}


/*
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n <= 1) return -1;
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (!knows(i, candidate)) candidate = i;
        }
        for (int i = 0; i < n; ++i) {
            if (i == candidate) continue;
            if (!knows(i, candidate) || knows(candidate, i)) return -1;
        }
        return candidate;
    }
};

*/