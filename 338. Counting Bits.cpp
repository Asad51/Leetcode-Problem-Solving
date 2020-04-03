class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> bits(num + 1, 0);
        for (int i = 1; i <= num; i++)
        {
            bits[i] = bits[i / 2];
            if (i % 2 == 1)
                bits[i]++;
        }
        return bits;
    }
};
