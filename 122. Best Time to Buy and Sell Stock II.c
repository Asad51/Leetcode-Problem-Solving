int maxProfit(int *prices, int pricesSize)
{
    int cnt = 0;
    for (int i = pricesSize - 1; i > 0; i--)
    {
        if (prices[i] > prices[i - 1])
            cnt += prices[i] - prices[i - 1];
    }

    return cnt;
}
