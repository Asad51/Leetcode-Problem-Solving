class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        int arr[10001] = {0};
        for (int i = 0; i < A.size(); i++)
        {
            if (arr[A[i]])
                return A[i];
            arr[A[i]]++;
        }
        return -1;
    }
};
