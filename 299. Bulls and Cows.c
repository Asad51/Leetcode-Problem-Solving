int min(int a, int b)
{
    return (a < b) ? a : b;
}

void toString(int n, char *s)
{
    int i = 0;
    int a[15], m = 0;
    if (!n)
        s[i++] = '0';
    while (n)
    {
        a[m++] = n % 10;
        n /= 10;
    }
    for (int k = m - 1; k >= 0; k--)
        s[i++] = '0' + a[k];
    s[i] = '\0';
}

char *getHint(char *secret, char *guess)
{
    int a[10], b[10];
    int bulls = 0, cows = 0;
    char *hint = malloc(30 * sizeof(char));

    for (int i = 0; i < 10; i++)
        a[i] = b[i] = 0;

    for (int i = 0; secret[i]; i++)
    {
        int n = secret[i] - '0', m = guess[i] - '0';
        a[n]++;
        b[m]++;
        if (secret[i] == guess[i])
            bulls++;
    }

    for (int i = 0; i < 10; i++)
        cows += min(a[i], b[i]);
    cows -= bulls;

    int j = 0;
    char str1[15], str2[15];
    toString(bulls, str1), toString(cows, str2);

    for (int k = 0; str1[k]; k++)
        hint[j++] = str1[k];
    hint[j++] = 'A';
    for (int k = 0; str2[k]; k++)
        hint[j++] = str2[k];
    hint[j++] = 'B';
    hint[j] = '\0';
    return hint;
}
