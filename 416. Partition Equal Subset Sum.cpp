class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        int dp[n + 1][sum + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (!i || !j)
                    dp[i][j] = 0;
                else if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], nums[i - 1] + dp[i - 1][j - nums[i - 1]]);
            }
        }

        if (dp[n][sum / 2] * 2 == sum)
            return true;
        return false;
    }
};
