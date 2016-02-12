class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() {
        children.resize(26, NULL);
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
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

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (!cur->children[index]) return false;
            cur = cur->children[index];
        }
        return cur->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int index = prefix[i] - 'a';
            if (!cur->children[index]) return false;
            cur = cur->children[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");