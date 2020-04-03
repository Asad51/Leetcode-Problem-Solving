
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    int *res = malloc(2 * sizeof(int));
    int arr[10001];

    for (int i = 0; i <= numsSize; i++)
        arr[i] = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (arr[nums[i]])
        {
            res[0] = nums[i];
            break;
        }
        arr[nums[i]]++;
    }

    res[1] = res[0];
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++)
        res[1] ^= (nums[i] ^ (i + 1));

    return res;
}
