int toInt(char a, char b)
{
    return (a - '0') * 10 + (b - '0');
}

char *freqAlphabets(char *s)
{
    char *str;
    str = (char *)malloc(1001 * sizeof(char));
    int j = 0, sz = strlen(s);
    for (int i = 0; i < sz; i++)
    {
        if (i + 2 < sz && s[i + 2] == '#')
        {
            *(str + j++) = 'a' + toInt(s[i], s[i + 1]) - 1;
            i += 2;
        }
        else
        {
            *(str + j++) = s[i] - '0' + 'a' - 1;
        }
    }
    str[j] = '\0';
    return str;
}
