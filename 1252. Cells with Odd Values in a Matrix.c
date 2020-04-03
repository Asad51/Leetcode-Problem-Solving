int oddCells(int n, int m, int **indices, int indicesSize, int *indicesColSize)
{
    int arr[n][m], cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = 0;

    for (int i = 0; i < indicesSize; i++)
    {
        for (int j = 0; j < m; j++)
            arr[indices[i][0]][j]++;
        for (int j = 0; j < n; j++)
            arr[j][indices[i][1]]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] & 1)
                cnt++;
        }
    }
    return cnt;
}
