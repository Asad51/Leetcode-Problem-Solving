class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> cnt(1001, 0), res;
        for (int i = 0; i < arr1.size(); i++)
            cnt[arr1[i]]++;

        for (int i = 0; i < arr2.size(); i++)
        {
            while (cnt[arr2[i]] && cnt[arr2[i]]--)
                res.push_back(arr2[i]);
        }

        for (int i = 0; i < 1001; i++)
        {
            while (cnt[i] && cnt[i]--)
                res.push_back(i);
        }
        return res;
    }
};
