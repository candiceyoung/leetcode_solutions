class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int distance = INT_MAX;
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i] == word1) {
                for (int j = i + 1; j < words.size(); ++j) {
                    if (words[j] == word2) {
                        if (distance > (j - i)) distance = j - i;
                        continue;
                    }
                }
            }
            else if (words[i] == word2) {
                for (int j = i + 1; j < words.size(); ++j) {
                    if (words[j] == word1) {
                        if (distance > (j - i)) distance = j - i;
                        continue;
                    }
                }
            }
        }
        return distance;
    }
};