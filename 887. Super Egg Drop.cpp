class Solution
{
public:
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int min(int a, int b)
    {
        return (a < b) ? a : b;
    }

    int superEggDrop(int k, int n)
    {
        int dp[n + 1][k + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = 0;
        int m = 0;
        while (dp[m][k] < n)
        {
            m++;
            for (int i = 1; i <= k; ++i)
                dp[m][i] = dp[m - 1][i - 1] + dp[m - 1][i] + 1;
        }
        return m;
    }
};
