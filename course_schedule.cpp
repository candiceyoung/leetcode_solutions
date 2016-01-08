class Solution {
public:
    // find the node with 0 in-degree first
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int size = prerequisites.size();
        if (size == 0) return true;
        if (numCourses == 0) return true;
        vector<unordered_set<int>> list(numCourses);
        
        for (int i = 0; i < size; ++i) {
            list[prerequisites[i].first].insert(prerequisites[i].second);
        }
        vector<int> degree(numCourses, 0);
        for (int i = 0; i < list.size(); ++i) {
            for (unordered_set<int>::iterator it = list[i].begin(); it != list[i].end(); ++it) {
                degree[*it]++;
            } 
        }
        for (int i = 0; i < numCourses; ++i) {
            int j;
            for (j = 0; j < numCourses && degree[j] != 0; ++j);
            if (j == numCourses) return false;
            degree[j] = -1;
            for (unordered_set<int>::iterator it = list[j].begin(); it != list[j].end(); ++it) {
                degree[*it]--;
            }
        }
        return true;
    }
    // topological sort
    /*
    void helper(vector<vector<int>> &graph, vector<bool> &visited, int i, stack<int> &stk) {
        visited[i] = true;
        for (vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
            if (!visited[*it]) helper(graph, visited, *it, stk);
        }
        stk.push(i);
    }
    bool canFinish(int numberCourses, vector<pair<int, int>> &prerequisites) {
        if (prerequisites.size() == 0) return true;
        if (numberCourses == 0) return true;
        vector<vector<int>> graph(numberCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<bool> visited(numberCourses, false);
        stack<int> stk;
        for (int i = 0; i < numberCourses; ++i) {
            if (!visited[i]) helper(graph, visited, i, stk);
        }
        for (int i = 0; i < numberCourses; ++i) {
            visited[i] = false;
        }
        int top = stk.top();
        stk.pop();
        visited[top] = true;
        int size = stk.size();
        for (int i = 0; i < size; ++i) {
            int top = stk.top();
            stk.pop();
            visited[top] = true;
            for (vector<int>::iterator it = graph[top].begin(); it != graph[top].end(); ++it) {
                if (visited[*it]) return false;
            }
        }
        return true;
    }
    */
    // dfs
    /*
    void helper(vector<vector<int>> &graph, vector<int> &visited, int i, bool &cycle) {
        if (visited[i] == 1) {cycle = true; return;}
        visited[i] = 1;
        for (vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
            helper(graph, visited, *it, cycle);
            if (cycle) return;
        }
        visited[i] = 2;
    }
    bool canFinish(int numberCourses, vector<pair<int, int>> &prerequisites) {
        if (prerequisites.size() == 0) return true;
        if (numberCourses == 0) return true;
        vector<vector<int>> graph(numberCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> visited(numberCourses, 0);
        bool cycle = false;
        for (int i = 0; i < numberCourses; ++i) {
            if (cycle) return false;
            if (!visited[i]) helper(graph, visited, i, cycle);
        }
        return !cycle;
    }
    */
};