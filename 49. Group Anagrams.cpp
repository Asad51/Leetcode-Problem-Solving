class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        map<string, vector<string>>::iterator it;
        vector<vector<string>> result;

        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(tmp);
        }

        for (it = mp.begin(); it != mp.end(); it++)
            result.push_back(it->second);

        return result;
    }
};
