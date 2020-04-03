struct TrieNode
{
    bool isLeaf;
    TrieNode *childs[26];
    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
            childs[i] = NULL;
    }
};

class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *tmp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (!tmp->childs[idx])
                tmp->childs[idx] = new TrieNode();
            tmp = tmp->childs[idx];
        }
        tmp->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *tmp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (!tmp->childs[idx])
                return false;
            tmp = tmp->childs[idx];
        }
        return tmp->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *tmp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int idx = prefix[i] - 'a';
            if (!tmp->childs[idx])
                return false;
            tmp = tmp->childs[idx];
        }
        return true;
    }

    ~Trie()
    {
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
