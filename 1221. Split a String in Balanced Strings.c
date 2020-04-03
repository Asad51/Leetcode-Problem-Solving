
int balancedStringSplit(char *s)
{
    int l = 0, r = 0, cnt = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == 'L')
            l++;
        else
            r++;
        if (l == r)
        {
            l = r = 0;
            cnt++;
        }
    }
    return cnt;
}
