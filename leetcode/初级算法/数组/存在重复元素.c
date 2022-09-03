bool containsDuplicate(int* nums, int numsSize) {
    struct HashMap {
        int key;
        int val;
        UT_hash_handle hh;
    };

    struct HashMap* users = NULL;

    for (int i = 0; i < numsSize; i++)
    {
        struct HashMap* tmp;
        HASH_FIND_INT(users, &nums[i], tmp);
        if (tmp == NULL)
        {
            tmp = (struct HashMap*)malloc(sizeof * tmp);
            tmp->key = nums[i];
            tmp->val = 1;
            HASH_ADD_INT(users, key, tmp);
        }
        else
        {
            return true;
        }

    }

    return false;

}