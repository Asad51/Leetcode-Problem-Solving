#define MAXC 26

struct Node
{
    bool isLeaf;
    Node *childs[MAXC];
    Node()
    {
        isLeaf = false;
        for (int i = 0; i < MAXC; i++)
            childs[i] = NULL;
    }
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

class StreamChecker
{
    Node *root;
    int s = 0, e = 0, maxWordLen = 0;
    string str;

    void insert(string word)
    {
        Node *tmp = root;
        for (int i = word.size() - 1; i >= 0; i--)
        {
            int idx = word[i] - 'a';
            if (!tmp->childs[idx])
                tmp->childs[idx] = new Node();
            tmp = tmp->childs[idx];
        }
        tmp->isLeaf = true;
        maxWordLen = max(maxWordLen, word.size());
    }

    bool find(int s, int e)
    {
        Node *tmp = root;
        for (int i = e - 1; i >= s; i--)
        {
            int idx = str[i] - 'a';
            if (!tmp->childs[idx])
                return false;
            tmp = tmp->childs[idx];
            if (tmp->isLeaf)
                return true;
        }
        return tmp->isLeaf;
    }

public:
    StreamChecker(vector<string> &words)
    {
        root = new Node();

        for (int i = 0; i < words.size(); i++)
            insert(words[i]);
    }

    bool query(char letter)
    {
        str.append(1, letter);
        e++;
        if (e - s > maxWordLen)
            s++;

        return find(s, e);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
