int abs(int a)
{
    return (a < 0) ? -a : a;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int minTimeToVisitAllPoints(int **points, int pointsSize, int *pointsColSize)
{
    int distance = 0;
    for (int i = 1; i < pointsSize; i++)
    {
        distance += max(abs(points[i - 1][0] - points[i][0]), abs(points[i - 1][1] - points[i][1]));
    }
    return distance;
}
