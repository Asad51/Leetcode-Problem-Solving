#define MAXC 26

struct TrieNode
{
    int count;
    TrieNode *childs[MAXC];
    TrieNode()
    {
        count = 0;
        for (int i = 0; i < MAXC; i++)
            childs[i] = NULL;
    }
};

struct Result
{
    string word;
    int count;
};

class Solution
{
    TrieNode *root;
    int k, n;
    vector<Result> tmpResult;

    void insertWord(string word)
    {
        TrieNode *tmp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (!tmp->childs[idx])
                tmp->childs[idx] = new TrieNode();
            tmp = tmp->childs[idx];
        }
        tmp->count++;
    }

    void findWord(TrieNode *node, string w)
    {
        if (!node)
            return;
        if (node->count)
        {
            tmpResult[n] = {w, node->count};
            for (int i = n; i > 0; i--)
            {
                if (tmpResult[i].count > tmpResult[i - 1].count)
                {
                    Result tmp = tmpResult[i];
                    tmpResult[i] = tmpResult[i - 1];
                    tmpResult[i - 1] = tmp;
                }
                else
                    break;
            }
            n = (n >= k) ? n : n + 1;
        }

        for (int i = 0; i < MAXC; i++)
        {
            if (node->childs[i])
            {
                char ch = i + 'a';
                findWord(node->childs[i], w + ch);
            }
        }
    }

public:
    Solution()
    {
        root = new TrieNode();
    }

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> result;
        this->k = k;
        n = 0;
        tmpResult.clear();
        tmpResult.resize(k + 1);

        for (int i = 0; i < words.size(); i++)
            insertWord(words[i]);

        findWord(root, "");
        for (int i = 0; i < tmpResult.size() && i < k; i++)
            result.push_back(tmpResult[i].word);
        return result;
    }

    ~Solution()
    {
        delete root;
    }
};
