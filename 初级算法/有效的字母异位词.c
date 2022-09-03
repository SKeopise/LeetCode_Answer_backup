bool isAnagram(char * s, char * t){
    struct HashMap{
        int key;
        int val;
        int val2;
        UT_hash_handle hh;
    };

    struct HashMap* users = NULL;
    int m = strlen(s);
    int n = strlen(t);


    for(int i = 0;i<m;i++)
    {
        struct HashMap* tmp;
        int ikey = s[i];
        HASH_FIND_INT(users,&ikey,tmp);
        if(tmp == NULL)
        {
            tmp = (struct HashMap*)malloc(sizeof *tmp);
            tmp->key = ikey;
            tmp->val = 1;
            tmp->val2 = 0;
            HASH_ADD_INT(users,key,tmp);
        }
        else
        {
            tmp->val++;
        }
    }
    for(int j = 0;j<n;j++)
    {
        struct HashMap* tmp;
        int ikey = t[j];
        HASH_FIND_INT(users,&ikey,tmp);
        if(tmp == NULL)
        {
            return false;
        }
        else
        {
            tmp->val2++;
        }       
    }

    if(n>=m)
    {
        for(int k = 0;k<n;k++)
        {
            struct HashMap* tmp;
            int ikey = t[k];
            HASH_FIND_INT(users,&ikey,tmp);
            if(tmp->val != tmp->val2)
            {
                return false;
            }   
        }
    }
    else
    {
        for(int k = 0;k<m;k++)
        {
            struct HashMap* tmp;
            int ikey = s[k];
            HASH_FIND_INT(users,&ikey,tmp);
            if(tmp->val != tmp->val2)
            {
                return false;
            }   
        }        
    }


    return true;
}