class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n = grid.size(), cnt = 0;
        int rowMax[n], colMax[n];
        for (int i = 0; i < n; i++)
            rowMax[i] = colMax[i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    rowMax[i] = max(rowMax[i], grid[i][j]);
                    colMax[j] = max(colMax[j], grid[i][j]);
                    cnt++;
                }
            }
        }

        for (int i = 0; i < n; i++)
            cnt += rowMax[i] + colMax[i];
        return cnt;
    }
};
