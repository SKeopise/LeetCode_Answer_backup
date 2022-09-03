void QuickSort(int array[], int low, int high);

int singleNumber(int* nums, int numsSize) {

	int i;

	if (numsSize == 1)
	{
		return nums[0];
	}

	QuickSort(nums, 0, numsSize - 1);

	if (nums[0] != nums[1])
	{
		return nums[0];
	}
	else if (nums[numsSize - 2] != nums[numsSize - 1])
	{
		return nums[numsSize - 1];
	}

	for (i = 1; i < numsSize - 2; i++)
	{
		if ((nums[i] != nums[i - 1]) && (nums[i] != nums[i + 1]))
		{
			return nums[i];
		}
	}



	return 0;
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