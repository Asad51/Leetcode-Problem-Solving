class Solution
{
public:
    int maximum69Number(int num)
    {
        int arr[5], m = 0, n = 0;
        while (num)
        {
            arr[m++] = num % 10;
            num /= 10;
        }
        bool isChanged = false;
        for (int i = m - 1; i >= 0; i--)
        {
            if (!isChanged && arr[i] == 6)
            {
                n = n * 10 + 9;
                isChanged = true;
            }
            else
                n = n * 10 + arr[i];
        }
        return n;
    }
};
