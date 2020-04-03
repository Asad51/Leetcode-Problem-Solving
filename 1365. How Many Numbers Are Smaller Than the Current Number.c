
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    int *arr = malloc(101 * sizeof(int)), *result = malloc(numsSize * sizeof(int)), sum = 0;

    for (int i = 0; i <= 100; i++)
        arr[i] = 0;

    for (int i = 0; i < numsSize; i++)
        arr[nums[i]]++;
    for (int i = 0; i <= 100; i++)
    {
        int tmp = arr[i];
        arr[i] = sum;
        sum += tmp;
    }

    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
        result[i] = arr[nums[i]];

    free(arr);
    return result;
}
