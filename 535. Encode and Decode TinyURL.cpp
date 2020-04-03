#define MAXC 62
#define MAXS 30
#define MAXE 6

struct Node
{
    bool isLeaf;
    string url;
    Node *childs[MAXC];
    Node()
    {
        isLeaf = false;
        for (int i = 0; i < MAXC; i++)
            childs[i] = NULL;
    }
};

string generateRandomString()
{
    string str;
    for (int i = 0; i < 6; i++)
    {
        char ch;
        int idx = rand() % MAXC;
        if (idx < 10)
            ch = '0' + idx;
        else if (idx < 36)
            ch = 'A' + (idx % 26);
        else
            ch = 'a' + (idx % 26);
        str.append(1, ch);
    }
    return str;
}

int getIdx(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A';
    return ch - 'a';
}

class Solution
{
    Node *root;

    void insert(string str, string url)
    {
        Node *tmp = root;
        for (int i = 0; i < str.size(); i++)
        {
            int idx = getIdx(str[i]);
            if (!tmp->childs[idx])
                tmp->childs[idx] = new Node();
            tmp = tmp->childs[idx];
        }
        tmp->isLeaf = true;
        tmp->url = url;
    }

    bool isExist(string str)
    {
        Node *tmp = root;
        for (int i = 0; str[i]; i++)
        {
            int idx = getIdx(str[i]);
            if (!tmp->childs[idx])
                return false;
            tmp = tmp->childs[idx];
        }
        if (tmp->isLeaf)
            return true;
        return false;
    }

    string find(string str)
    {
        Node *tmp = root;
        for (int i = 0; i < str.size(); i++)
        {
            int idx = getIdx(str[i]);
            if (!tmp->childs[idx])
                return "";
            tmp = tmp->childs[idx];
        }
        if (tmp->isLeaf)
            return tmp->url;
        return "";
    }

public:
    Solution()
    {
        root = new Node();
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string str, shortUrl = "";
        do
        {
            str = generateRandomString();
        } while (isExist(str));

        insert(str, longUrl);
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return find(shortUrl);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
