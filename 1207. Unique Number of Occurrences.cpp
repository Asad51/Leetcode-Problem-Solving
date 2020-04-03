class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> freq, oc;
        map<int, int>::iterator it;
        for (int i = 0; i < arr.size(); i++)
            freq[arr[i]]++;

        for (it = freq.begin(); it != freq.end(); it++)
        {
            if (oc[it->second])
                return false;
            oc[it->second]++;
        }

        return true;
    }
};
