class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int flag = 0;
        if (word1 == word2) flag = 1;
        int distance = INT_MAX;
        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < words.size(); ++i) {
            if (flag) {
                if (words[i] == word1) {
                    if ((pos1 != -1) && (distance > (i - pos1))) { 
                        distance = i - pos1;
                    }
                    pos1 = i;
                }
            }
            else {
                if (words[i] == word1) pos1 = i;
                else if (words[i] == word2) pos2 = i;
                else continue;
                if (pos1 != -1 && pos2 != -1) {
                    if (abs(pos1 - pos2) < distance) distance = abs(pos1 - pos2);
                }
            }
        }
        return distance;
    }
};