void moveZeroes(int* nums, int numsSize) {

    int i, j;
    int cnt = 0;


    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            cnt++;
        }
    }

    i = 0;
    j = 0;
    while (j < numsSize)
    {
        if (nums[j] != 0)
        {
            nums[i] = nums[j];
            i++;
        }

        j++;
    }

    for (j = 1; j <= cnt; j++)
    {
        nums[numsSize - j] = 0;
    }

    int* res = (int*)malloc(sizeof(int) * numsSize);
    res = nums;

    return res;

}