int isOddDigits(int num)
{
    int n = 0;
    while (num)
    {
        n++;
        num /= 10;
    }
    return n % 2;
}

int findNumbers(int *nums, int numsSize)
{
    int n = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (!isOddDigits(nums[i]))
            n++;
    }
    return n;
}
