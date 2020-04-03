class Solution
{
public:
    int fib(int N)
    {
        if (N < 2)
            return N;

        int res, a = 0, b = 1;
        for (int i = 2; i <= N; i++)
        {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};
