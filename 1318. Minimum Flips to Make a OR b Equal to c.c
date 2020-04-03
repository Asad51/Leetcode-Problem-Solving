int minFlips(int a, int b, int c)
{
    int cnt = 0;
    while (a || b || c)
    {
        if (c & 1)
        {
            if ((a & 1) == 0 && (b & 1) == 0)
                cnt++;
        }
        else
            cnt += (a & 1) + (b & 1);
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return cnt;
}
