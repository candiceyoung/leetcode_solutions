#define ALPHABETIC_SIZE 26
#define INDEX(c) (int(c-'a'))

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        children.resize(ALPHABETIC_SIZE, NULL);
        count = 0;
    }
    vector<TrieNode*> children; 
    int count;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        count = 0;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * cur = root;
        for(int i=0, len=word.size(); i<len; i++){
            int index = INDEX(word[i]);
            if(cur->children[index]==NULL){
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->count = ++count; 
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * cur = root;
        for(int i=0, len=word.size(); i<len; i++){
            int index = INDEX(word[i]);
            if(cur->children[index]==NULL)
                return false;
            cur = cur->children[index];
        }
        return (cur->count)!=0; 
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for(int i=0, len=prefix.size(); i<len; i++){
            int index = INDEX(prefix[i]);
            if(cur->children[index]==NULL)
                return false;
            cur = cur->children[index];
        }
        return true;     
    }

private:
    TrieNode* root;
    int count;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");