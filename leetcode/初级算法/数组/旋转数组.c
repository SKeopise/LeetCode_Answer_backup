void rotate(int* nums, int numsSize, int k) {

    int p[numsSize];
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        p[(i + k) % numsSize] = nums[i];
    }
    for (i = 0; i < numsSize; i++)
    {
        nums[i] = p[i];
    }

}
