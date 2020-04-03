struct Node
{
    bool isLeaf;
    Node *childs[10];
    Node()
    {
        isLeaf = false;
        for (int i = 0; i < 10; i++)
            childs[i] = NULL;
    }
};

class Solution
{
    Node *root;

    bool insert(int n)
    {
        Node *tmp = root;
        while (n)
        {
            int m = n % 10;
            n /= 10;
            if (!tmp->childs[m])
                tmp->childs[m] = new Node();
            tmp = tmp->childs[m];
        }
        if (tmp->isLeaf)
            return true;
        tmp->isLeaf = true;
        return false;
    }

public:
    Solution()
    {
        root = new Node();
    }

    bool isHappy(int n)
    {
        bool isHappy = false;
        do
        {
            int s = 0;
            while (n)
            {
                int r = n % 10;
                n /= 10;
                s += r * r;
            }
            if (s == 1)
                return true;
            n = s;
        } while (!insert(n));
        return false;
    }
};
