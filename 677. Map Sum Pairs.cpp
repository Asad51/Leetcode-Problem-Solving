struct Node
{
    int cnt;
    Node *childs[26];
    Node()
    {
        cnt = 0;
        for (int i = 0; i < 26; i++)
            childs[i] = nullptr;
    }
};

class MapSum
{
    Node *root;
    int s;

public:
    /** Initialize your data structure here. */
    MapSum()
    {
        root = new Node();
    }

    void insert(string key, int val)
    {
        Node *tmp = root;
        for (int i = 0; key[i]; i++)
        {
            int index = key[i] - 'a';
            if (!tmp->childs[index])
                tmp->childs[index] = new Node();
            tmp = tmp->childs[index];
        }
        tmp->cnt = val;
    }

    void calculateSum(Node *root)
    {
        if (!root)
            return;
        s += root->cnt;
        for (int i = 0; i < 26; i++)
            calculateSum(root->childs[i]);
    }

    int sum(string prefix)
    {
        Node *tmp = root;
        s = 0;
        for (int i = 0; prefix[i]; i++)
        {
            int index = prefix[i] - 'a';
            if (!tmp->childs[index])
                return 0;
            tmp = tmp->childs[index];
        }
        calculateSum(tmp);
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
