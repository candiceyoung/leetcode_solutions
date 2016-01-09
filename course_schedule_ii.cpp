#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    void helper(vector<vector<int>> &graph, vector<bool> &visited, int i, stack<int> &stk) {
        visited[i] = true;
        for (vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
            if (!visited[*it]) helper(graph, visited, *it, stk);
        }
        stk.push(i);
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int size = prerequisites.size();
        vector<int> result;
        if (numCourses == 0) return result;
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < size; ++i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<bool> visited(numCourses);
        stack<int> stk;
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) helper(graph, visited, i, stk);
        }
        for (int i = 0; i < numCourses; ++i) {
            visited[i] = false;
        }
        int top = stk.top();
        stk.pop();
        visited[top] = true;
        result.push_back(top);
        int stk_size = stk.size();
        for (int i = 0; i < stk_size; ++i) {
            int top = stk.top();
            stk.pop();
            visited[top] = true;
            for (int i = 0; i < graph[top].size(); ++i) {
                if (visited[graph[top][i]]) {
                    result.clear();
                    return result;
                }
            }
            result.push_back(top);
        }
        return result;
    }
};
int main(void) {
    Solution s;
    // vector<pair<int, int>> prerequisites = {{0, 1}, {0, 3}, {0, 4}, {1, 2}, {2, 3}, {2, 4}};
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result = s.findOrder(4, prerequisites);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
