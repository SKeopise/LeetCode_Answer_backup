struct my_struct {
    int key;
    int val;
    UT_hash_handle hh;
};


int firstUniqChar(char* s) {

    struct my_struct* users = NULL;

    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int ikey = s[i];
        struct my_struct* tmp;
        HASH_FIND_INT(users, &ikey, tmp);
        if (tmp == NULL)
        {
            tmp = malloc(sizeof(struct my_struct));
            tmp->key = ikey;
            tmp->val = 1;
            HASH_ADD_INT(users, key, tmp);
        }
        else
        {
            tmp->val++;
        }

    }
    for (int i = 0; i < n; i++)
    {
        int ikey = s[i];
        struct my_struct* tmp;
        HASH_FIND_INT(users, &ikey, tmp);
        if (tmp != NULL && tmp->val == 1)
        {
            return i;
        }
    }

    return -1;

}