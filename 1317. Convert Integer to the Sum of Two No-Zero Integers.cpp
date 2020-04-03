class Solution
{
public:
    bool isNoZero(int n)
    {
        while (n)
        {
            int rem = n % 10;
            n /= 10;
            if (rem == 0)
                return false;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> res;
        for (int i = 1; i < n; i++)
        {
            if (isNoZero(i) && isNoZero(n - i))
            {
                res.push_back(i);
                res.push_back(n - i);
                break;
            }
        }
        return res;
    }
};
