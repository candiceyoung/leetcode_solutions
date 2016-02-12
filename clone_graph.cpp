/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        mp[node] = copy;
        while (!q.empty()) {
            UndirectedGraphNode *top = q.front();
            q.pop();
            for (int i = 0; i < top->neighbors.size(); ++i) {
                UndirectedGraphNode *neighbor = top->neighbors[i];
                if (mp.find(neighbor) == mp.end()) {
                    // not found
                    UndirectedGraphNode *neighbor_copy = new UndirectedGraphNode(neighbor->label);
                    mp[neighbor] = neighbor_copy;
                    q.push(neighbor);
                }
                mp[top]->neighbors.push_back(mp[neighbor]);
            }
        }
        return copy;
    }
};