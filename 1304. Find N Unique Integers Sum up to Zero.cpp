class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> arr;
        for (int i = -1 * (n / 2); i <= n / 2; i++)
        {
            if (i == 0 && n % 2 == 0)
                continue;
            arr.push_back(i);
        }
        return arr;
    }
};
