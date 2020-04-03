class Solution
{
    int countBits(int n)
    {
        int cnt = 0;
        while (n)
        {
            cnt++;
            n &= (n - 1);
        }

        return cnt;
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                int n1 = countBits(arr[i]), n2 = countBits(arr[j]);
                if ((n2 < n1) || (n1 == n2 && arr[j] < arr[i]))
                {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        return arr;
    }
};
