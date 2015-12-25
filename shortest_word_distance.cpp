class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int distance = INT_MAX;
        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) pos1 = i;
            else if (words[i] == word2) pos2 = i;
            else continue;
            if (pos1 != -1 && pos2 != -1) {
                if (abs(pos1 - pos2) < distance) distance = abs(pos1 - pos2);
            }
        }
        return distance;
    }
};