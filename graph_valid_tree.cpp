class Solution {
public:
    bool isValid(int i, vector<int> &visited, vector<vector<int>> &graph, int former) {
        if (visited[i]) return false;
        visited[i] = true;
        for (int j = 0; j < graph[i].size(); ++j) {
            if (graph[i][j] == former) continue;
            if (isValid(graph[i][j], visited, graph, i) == false) return false;
        }
        return true;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int size = edges.size();
        if (size == 0 && n != 1) return false;
        if (size == 0 && n == 1) return true;
        vector<vector<int>> graph(n);
        vector<int> visited(n);
        int count = 0;
        for (int i = 0; i < size; ++i) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        for (int i = 0; i < n; ++i) {
            int former = -1;
            if (!visited[i]) {
                count++;
                if (isValid(i, visited, graph, former) == false) return false;
            }
        }
        if (count > 1) return false;
        else return true;
    }
};

/* Solution 2

class Solution {
private:
    int total;
public:
    int find(vector<int> &roots, int a) {
        if (roots[a] == -1) return a;
        else return find(roots, roots[a]);
    }
    void uni(vector<int> &roots, int a, int b) {
        int a_root = find(roots, a);
        int b_root = find(roots, b);
        roots[b_root] = a_root;
        total--;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int size = edges.size();
        if (size == 0 && n == 1) return true;
        else if (size == 0 && n != 1) return false;
        vector<int> roots(n, -1);
        total = n;
        for (int i = 0; i < size; ++i) {
            int from = edges[i].first;
            int to = edges[i].second;
            int from_root = find(roots, from);
            int to_root = find(roots, to);
            if (from_root == to_root) return false;
            uni(roots, from_root, to_root);
        }
        if (total == 1) return true;
        else return false;
    }
};

*/