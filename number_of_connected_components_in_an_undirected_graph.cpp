class Solution {
public:
    void dfs(int i, vector<bool> &visited, vector<vector<int>> &graph) {
        if (visited[i]) return;
        visited[i] = true;
        for (int j = 0; j < graph[i].size(); ++j) {
            dfs(graph[i][j], visited, graph);
        }
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n);
        int count = 0;
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                count++;
                dfs(i, visited, graph);
            }
        }
        return count;
    }
};
// Solution 2: union find
/*
class Solution {
private:
    int total;
public:
    int find(vector<int> &roots, int i) {
        if (roots[i] == -1) return i;
        else return find(roots, roots[i]);
    }
    int merge(vector<int> &roots, int a, int b) {
        int a_root = find(roots, a);
        int b_root = find(roots, b);
        if (a_root != b_root) {
            roots[b_root] = a_root;
            total--;
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        total = n;
        for (int i = 0; i < edges.size(); ++i) {
            int from = edges[i].first;
            int to = edges[i].second;
            merge(roots, from, to);
        }
        return total;
    }
};
*/