int subtractProductAndSum(int n)
{
    int sum = 0, prod = 1;
    while (n)
    {
        int rem = n % 10;
        n /= 10;
        sum += rem;
        prod *= rem;
    }
    return prod - sum;
}
