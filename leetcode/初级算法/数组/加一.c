/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int i, j;
    int cnt = 0;

    if (digitsSize == 1)
    {
        if (digits[0] != 9)
        {
            digits[0]++;
            int* res = (int*)malloc(sizeof(int) * digitsSize);
            res = digits;
            *returnSize = digitsSize;
            return res;
        }
        else
        {
            digitsSize++;
            int* res = (int*)malloc(sizeof(int) * digitsSize);
            res[0] = 1;
            res[1] = 0;
            *returnSize = digitsSize;
            return res;
        }

    }
    else
    {
        for (i = digitsSize - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i] += 1;

                for (j = i + 1; j < digitsSize; j++)
                {
                    digits[j] = 0;
                }
                break;
            }
            else
            {
                cnt++;
            }
        }


        if (cnt == digitsSize)
        {
            digitsSize++;
            int* res = (int*)malloc(sizeof(int) * digitsSize);
            res[0] = 1;
            for (i = 1; i < digitsSize; i++)
            {
                res[i] = 0;
            }
            *returnSize = digitsSize;

            return res;
        }
        else
        {
            int* res = (int*)malloc(sizeof(int) * digitsSize);
            res = digits;
            *returnSize = digitsSize;

            return res;
        }

    }


}