class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        int rem;
        bool isSelf;
        for (int i = left; i <= right; i++)
        {
            isSelf = true;
            int num = i;
            while (num != 0)
            {
                rem = num % 10;

                if (rem == 0 || i % rem != 0)
                {
                    isSelf = false;
                    break;
                }
                num = num / 10;
            }
            if (isSelf)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
