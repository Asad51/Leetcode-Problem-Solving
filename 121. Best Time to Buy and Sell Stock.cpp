class Solution
{
public:
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX, maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
            if (prices[i] < minPrice)
                minPrice = prices[i];
            else
                maxProfit = max(maxProfit, prices[i] - minPrice);

        return maxProfit;
    }
};
