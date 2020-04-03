class Solution
{
public:
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int maxDistToClosest(vector<int> &seats)
    {
        int left = -1, res = 0;
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i])
            {
                if (left == -1)
                    res = max(res, i);
                else
                    res = max(res, (i - left) / 2);
                left = i;
            }
        }
        res = max(res, seats.size() - 1 - left);
        return res;
    }
};
