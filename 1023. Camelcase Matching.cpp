class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> res;
        for (int i = 0; i < queries.size(); i++)
        {
            int l = 0;
            int isSimilar = true;
            for (int j = 0; j < queries[i].size(); j++)
            {
                if (queries[i][j] >= 'A' && queries[i][j] <= 'Z')
                {
                    if (queries[i][j] != pattern[l])
                    {
                        isSimilar = false;
                        res.push_back(false);
                        break;
                    }
                    l++;
                }
                else
                {
                    if (pattern[l] >= 'a' && pattern[l] <= 'z')
                    {
                        if (pattern[l] == queries[i][j])
                            l++;
                    }
                }
            }
            if (l < pattern.size() && isSimilar)
                res.push_back(false);
            else if (isSimilar)
                res.push_back(true);
        }
        return res;
    }
};
