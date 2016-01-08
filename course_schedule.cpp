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
};