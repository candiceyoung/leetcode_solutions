class WordDistance {
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> v1 = m[word1];
        vector<int> v2 = m[word2];
        int distance = INT_MAX;
        for (int i = 0; i < v1.size(); ++i) {
            for (int j = 0; j < v2.size(); ++j) {
                if (abs(v1[i] - v2[j]) < distance) distance = abs(v1[i] - v2[j]);
            }
        }
        return distance;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");