class Solution
{
    int upper_bound(vector<int> arr, int n)
    {
        int b = 0, e = n - 1, m;
        while (b <= e)
        {
            m = b + (e - b) / 2;
            if (arr[m] >= 0)
                b = m + 1;
            else
                e = m - 1;
        }
        return b;
    }

public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
            cnt += (grid[i].size() - upper_bound(grid[i], grid[i].size()));

        return cnt;
    }
};
