bool isAnagram(char *s, char *t)
{
    int a[256], b[256];
    for (int i = 0; i < 256; i++)
        a[i] = b[i] = 0;
    for (int i = 0; s[i]; i++)
        a[s[i]]++;
    for (int i = 0; t[i]; i++)
        b[t[i]]++;

    for (int i = 0; i < 256; i++)
    {
        if (a[i] != b[i])
            return false;
    }

    return true;
}
