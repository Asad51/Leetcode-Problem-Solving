class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        int minValue = 1000001;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            minValue = min(minValue, abs(arr[i] - arr[i - 1]));
            if (minValue == 0)
                break;
        }

        for (int i = 1; i < arr.size(); i++)
        {
            if (minValue == abs(arr[i] - arr[i - 1]))
            {
                tmp.clear();
                tmp.push_back(arr[i - 1]);
                tmp.push_back(arr[i]);
                res.push_back(tmp);
            }
        }

        return res;
    }
};
