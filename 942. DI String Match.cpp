class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        vector<int> res;
        int i = 0, d = S.size(), n = S.size();
        for (int j = 0; j < n; j++)
        {
            if (S[j] == 'I')
                res.push_back(i++);
            else
                res.push_back(d--);
        }
        res.push_back(i);
        return res;
    }
};
