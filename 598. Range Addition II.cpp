class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int x = m, y = n;
        for (int i = 0; i < ops.size(); i++)
        {
            for (int j = 0; j < ops[0].size(); j++)
            {
                x = min(x, ops[i][0]);
                y = min(y, ops[i][1]);
            }
        }

        return x * y;
    }
};
