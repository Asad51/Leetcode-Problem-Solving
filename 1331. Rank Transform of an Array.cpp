class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> res, tmp;
        map<int, int> mp;
        int rank = 1;
        if (arr.size() <= 0)
            return res;
        for (int i = 0; i < arr.size(); i++)
            tmp.push_back(arr[i]);
        sort(arr.begin(), arr.end());
        mp.insert(make_pair(arr[0], 1));
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[i - 1])
            {
                rank++;
                mp.insert(make_pair(arr[i], rank));
            }
        }
        for (int i = 0; i < arr.size(); i++)
            res.push_back(mp[tmp[i]]);

        return res;
    }
};
