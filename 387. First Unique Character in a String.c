int firstUniqChar(char *s)
{
    int arr[26];
    for (int i = 0; i < 26; i++)
        arr[i] = 0;
    for (int i = 0; s[i]; i++)
    {
        int idx = s[i] - 'a';
        arr[idx]++;
    }

    for (int i = 0; s[i]; i++)
    {
        int idx = s[i] - 'a';
        if (arr[idx] == 1)
            return i;
    }

    return -1;
}
