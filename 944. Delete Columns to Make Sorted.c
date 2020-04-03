int strLen(char *s)
{
    int l = 0;
    while (s[l])
        l++;
    return l;
}

int minDeletionSize(char **A, int ASize)
{
    int len = strLen(A[0]), cnt = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < ASize - 1; j++)
        {
            if (A[j][i] > A[j + 1][i])
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
