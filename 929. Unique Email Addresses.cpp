class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> res;
        string tmp;
        for (int i = 0; i < emails.size(); i++)
        {
            tmp.clear();
            bool isPlusFound = false, isAtFound = false;
            for (int j = 0; j < emails[i].size(); j++)
            {
                if (emails[i][j] == '.')
                {
                    if (isAtFound)
                        tmp.push_back(emails[i][j]);
                }
                else if (emails[i][j] == '+')
                    isPlusFound = true;
                else if (emails[i][j] == '@')
                {
                    isAtFound = true;
                    tmp.push_back(emails[i][j]);
                }
                else
                {
                    if (isAtFound || !isPlusFound)
                        tmp.push_back(emails[i][j]);
                }
            }
            res.insert(tmp);
        }

        return res.size();
    }
};
