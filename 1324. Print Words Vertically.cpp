class Solution
{
    int maxLen;

public:
    int max(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }
    vector<string> getWords(string s)
    {
        vector<string> res;
        string tmp;
        tmp.clear();
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                if (tmp.size())
                {
                    cout << tmp << endl;
                    maxLen = max(maxLen, tmp.size());
                    res.push_back(tmp);
                }
                tmp.clear();
            }
            else
                tmp.push_back(s[i]);
        }
        return res;
    }

    string trim(string s)
    {
        string tmp, rTmp;
        tmp.clear(), rTmp.clear();
        bool isEmpty = true;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (isEmpty && s[i] == ' ')
                continue;
            else
            {
                isEmpty = false;
                tmp.push_back(s[i]);
            }
        }

        for (int i = tmp.size() - 1; i >= 0; i--)
            rTmp.push_back(tmp[i]);
        return rTmp;
    }

    vector<string> printVertically(string s)
    {
        maxLen = 0;
        vector<string> words = getWords(s), res;
        string tmp;
        for (int i = 0; i < maxLen; i++)
        {
            tmp.clear();
            for (int j = 0; j < words.size(); j++)
            {
                //cout << words[j] << endl;
                if (i < words[j].size())
                {
                    //cout << words[j][i];
                    tmp.push_back(words[j][i]);
                }
                else
                    tmp.push_back(' ');
            }
            //cout << endl;
            if (tmp.size())
            {
                res.push_back(trim(tmp));
                //cout << tmp << endl;
            }
        }
        return res;
    }
};
