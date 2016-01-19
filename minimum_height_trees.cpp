class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        vector<int> current;
        if (n == 1) {
            current.push_back(0);
            return current;
        }
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i].first].insert(edges[i].second);
            graph[edges[i].second].insert(edges[i].first);
        }
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) current.push_back(i);
        }
        while (true) {
            vector<int> next;
            for (int i = 0; i < current.size(); ++i) {
                for (unordered_set<int>::iterator it = graph[current[i]].begin(); it != graph[current[i]].end(); ++it) {
                    graph[*it].erase(current[i]);
                    if (graph[*it].size() == 1) next.push_back(*it);
                }
            }
            if (next.empty()) return current;
            current = next;
        }
    }
};