int heightChecker(int *heights, int heightsSize)
{
    int h[101] = {0}, rH[heightsSize], p = 0, cnt = 0;
    for (int i = 0; i < heightsSize; i++)
        h[heights[i]]++;
    for (int i = 0; i < 101; i++)
    {
        while (h[i])
        {
            rH[p++] = i;
            h[i]--;
        }
    }

    for (int i = 0; i < heightsSize; i++)
        if (heights[i] != rH[i])
            cnt++;

    return cnt;
}
