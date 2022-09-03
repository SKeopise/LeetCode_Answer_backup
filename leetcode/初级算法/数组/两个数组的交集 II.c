/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getStdandard(int array[], int low, int high);
void QuickSort(int array[], int low, int high);

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int m = 0, n = 0;
    int k = 0;

    int minLen = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* res = (int*)malloc(sizeof(int) * minLen);
    if (res == NULL) {
        *returnSize = 0;
        return res;
    }

    QuickSort(nums1, 0, nums1Size - 1);
    QuickSort(nums2, 0, nums2Size - 1);

    while (m < nums1Size && n < nums2Size)
    {
        if (nums1[m] == nums2[n])
        {
            res[k] = nums1[m];
            k++;
            m++;
            n++;
        }
        else
        {
            if (nums1[m] > nums2[n])
            {
                n++;
            }
            else
            {
                m++;
            }
        }

    }

    *returnSize = k;



    return res;
}


int getStdandard(int array[], int low, int high)
{
    int key = array[low];

    while (low < high)
    {
        while (low < high && array[high] >= key)
        {
            high--;
        }
        if (low < high)
        {
            array[low] = array[high];
        }

        while (low < high && array[low] <= key)
        {
            low++;
        }
        if (low < high)
        {
            array[high] = array[low];
        }
    }
    array[low] = key;

    return low;
}

void QuickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int standard = getStdandard(array, low, high);
        QuickSort(array, low, standard - 1);
        QuickSort(array, standard + 1, high);
    }
}