class TrieNode {
public:
    bool isEnd;
    vector<TrieNode *> children;
    TrieNode() {
        children.resize(26, NULL);
        isEnd = false;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return recursive(word, 0, root);
    }
private:
    TrieNode *root;
    bool recursive(string word, int start, TrieNode *root) {
        TrieNode *cur = root;
        for (int i = start; i < word.size(); ++i) {
            if (cur && word[i] != '.') {
                int index = word[i] - 'a';
                if (!cur->children[index]) return false;
                cur = cur->children[index];
            }
            else if (cur && word[i] == '.') {
                TrieNode *temp = cur;
                for (int j = 0; j < 26; ++j) {
                    cur = temp->children[j];
                    if (recursive(word, i + 1, cur)) return true;
                }
                return false;
            }
        }
        return cur && cur->isEnd;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");