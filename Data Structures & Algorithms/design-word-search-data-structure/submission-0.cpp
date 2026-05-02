class WordDictionary {
    struct Trie {
        vector<Trie*> children{26, nullptr};
        bool is_leaf = false;

        ~Trie () {
            for (auto child: children) {
                delete child;
            }
        }
    };
    Trie* root = new Trie();
public:
    WordDictionary() {}
    
    void addWord(string word) {
        Trie* pointer = root;
        for (auto ch: word) {
            if (!pointer->children[ch - 'a']) {
                Trie* node = new Trie();
                pointer->children[ch - 'a'] = node;
            }
            pointer = pointer->children[ch - 'a'];
        }
        pointer->is_leaf = true;
    }

    bool search_init(const string& word, int i, Trie* node) {
        if (!node) return false;
        if (i == word.size()) return node->is_leaf;
        char ch = word[i];
        if (ch == '.') {
            for (auto child: node->children) {
                if (search_init(word, i + 1, child)) return true;
            }
            return false;
        }
        return search_init(word, i + 1, node->children[ch - 'a']);
    }
    bool search(string word) {
        return search_init(word, 0, root);
    }
};
