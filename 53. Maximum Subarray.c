int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxSubArray(int *nums, int numsSize)
{
    int ans = INT_MIN, sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum = max(sum + nums[i], nums[i]);
        ans = max(ans, sum);
    }

    return ans;
}
