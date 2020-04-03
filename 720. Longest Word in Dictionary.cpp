struct Node
{
    char ch;
    bool isLeaf;
    Node *childs[26];
    Node(char c)
    {
        ch = c;
        isLeaf = false;
        for (int i = 0; i < 26; i++)
            childs[i] = nullptr;
    }
};

class Solution
{
    Node *root;
    string s;

public:
    Solution()
    {
        root = new Node('$');
        root->isLeaf = true;
        s = "";
    }

    void search(Node *root, string tmp)
    {
        if (tmp.size() > s.size())
            s = tmp;
        for (int i = 0; i < 26; i++)
        {
            if (root->childs[i] && root->childs[i]->isLeaf)
                search(root->childs[i], tmp + root->childs[i]->ch);
        }
    }

    string longestWord(vector<string> &words)
    {
        Node *tmp;
        for (int i = 0; i < words.size(); i++)
        {
            tmp = root;
            for (int j = 0; j < words[i].size(); j++)
            {
                int index = words[i][j] - 'a';
                if (!tmp->childs[index])
                    tmp->childs[index] = new Node(words[i][j]);

                tmp = tmp->childs[index];
            }
            tmp->isLeaf = true;
        }

        search(root, "");

        return s;
    }
};
