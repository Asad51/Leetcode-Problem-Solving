struct Node
{
    bool isLeaf;
    Node *childs[26];
    Node()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
            childs[i] = nullptr;
    }
};

class WordDictionary
{
    Node *root;
    bool isFound;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        Node *tmp = root;
        for (int i = 0; word[i]; i++)
        {
            int index = word[i] - 'a';
            if (!tmp->childs[index])
                tmp->childs[index] = new Node();
            tmp = tmp->childs[index];
        }
        tmp->isLeaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    void searchWord(Node *root, string word, int i)
    {
        if (!word[i])
        {
            isFound = root->isLeaf;
            return;
        }
        if (word[i] == '.')
        {
            for (int j = 0; j < 26; j++)
            {
                if (root->childs[j])
                    searchWord(root->childs[j], word, i + 1);
                if (isFound)
                    return;
            }
        }
        else
        {
            int index = word[i] - 'a';
            if (root->childs[index])
                searchWord(root->childs[index], word, i + 1);
        }
    }

    bool search(string word)
    {
        isFound = false;
        searchWord(root, word, 0);
        return isFound;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
