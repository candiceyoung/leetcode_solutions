class Solution {
private:
    unordered_map<string, multiset<string> > mp;
    vector<string> route;
public:
    void dfs(string start) {
        while (mp[start].size()) {
            string next = *mp[start].begin();
            mp[start].erase(mp[start].begin());
            dfs(next);
        }
        route.push_back(start);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (int i = 0; i < tickets.size(); ++i) {
            mp[tickets[i].first].insert(tickets[i].second);
        }
        dfs("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};