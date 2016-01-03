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