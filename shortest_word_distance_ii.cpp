class WordDistance {
private:
    unordered_map<string, vector<int>> mp;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            mp[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, distance = INT_MAX;
        while (i < mp[word1].size() && j < mp[word2].size()) {
            distance = min(distance, abs(mp[word1][i] - mp[word2][j]));
            mp[word1][i] < mp[word2][j] ? i++ : j++;
        }
        return distance;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");