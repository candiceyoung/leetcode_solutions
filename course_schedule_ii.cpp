#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    void helper(vector<vector<int>> &graph, stack<int> &stk, int i, vector<bool> &visited) {
        visited[i] = true;
        for (int j = 0; j < graph[i].size(); ++j) {
            if (!visited[graph[i][j]]) helper(graph, stk, graph[i][j], visited);
        }
        stk.push(i);
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        int size = prerequisites.size();
        if (numCourses == 0) return result;
        if (size == 0) {
            for (int i = 0; i < numCourses; ++i) {
                result.push_back(i);
            }
            return result;
        }
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < size; ++i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        stack<int> stk;
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) helper(graph, stk, i, visited);
        }
        for (int i = 0; i < numCourses; ++i) visited[i] = false;
        while (!stk.empty()) {
            int temp = stk.top();
            visited[temp] = true;
            for (int i = 0; i < graph[temp].size(); ++i) {
                if (visited[graph[temp][i]]) {
                    result.clear();
                    return result;
                }
            }
            result.push_back(temp);
            stk.pop();
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
