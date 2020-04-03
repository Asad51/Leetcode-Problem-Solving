#define MAXC 26

struct TrieNode
{
    bool isLeaf;
    TrieNode *childs[MAXC];
    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < MAXC; i++)
            childs[i] = NULL;
    }
};

class MagicDictionary
{
    TrieNode *root;
    bool isFound;

    void insert(string s)
    {
        TrieNode *tmp = root;
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (!tmp->childs[index])
                tmp->childs[index] = new TrieNode();
            tmp = tmp->childs[index];
        }
        tmp->isLeaf = true;
    }

    void find(TrieNode *node, string word, int i, int d)
    {
        if (!node || d > 1)
            return;

        if (isFound || i == word.size())
        {
            if (d == 1 && node->isLeaf)
                isFound = true;
            return;
        }

        for (int j = 0; j < MAXC; j++)
        {
            int index = word[i] - 'a';
            find(node->childs[j], word, i + 1, (index == j) ? d : d + 1);
        }
    }

public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        root = new TrieNode();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for (int i = 0; i < dict.size(); i++)
            insert(dict[i]);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        isFound = false;
        find(root, word, 0, 0);
        return isFound;
    }

    ~MagicDictionary()
    {
        delete (root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
