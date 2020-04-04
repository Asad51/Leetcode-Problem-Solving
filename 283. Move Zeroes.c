void moveZeroes(int *nums, int numsSize)
{
    int i, j;
    for (i = 0, j = 0; j < numsSize;)
    {
        if (nums[i] == 0)
        {
            if (nums[j])
                nums[i++] = nums[j];
            nums[j++] = 0;
        }
        else
            i++, j++;
    }
}
