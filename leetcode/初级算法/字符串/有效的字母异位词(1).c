bool isAnagram(char * s, char * t){
    struct HashMap{
        int key;
        int val;
        UT_hash_handle hh;
    };

    struct HashMap* users = NULL;
    int m = strlen(s);
    int n = strlen(t);

    if(m<=n)
    {
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
                if(tmp->val <= 0)
                {
                    return false;
                }
                tmp->val--;           
            }       
        }
    }
    else
    {
        for(int i = 0;i<n;i++)
        {
            struct HashMap* tmp;
            int ikey = t[i];
            HASH_FIND_INT(users,&ikey,tmp);
            if(tmp == NULL)
            {
                tmp = (struct HashMap*)malloc(sizeof *tmp);
                tmp->key = ikey;
                tmp->val = 1;
                HASH_ADD_INT(users,key,tmp);
            }
            else
            {
                tmp->val++;
            }
        }

        for(int j = 0;j<m;j++)
        {
            struct HashMap* tmp;
            int ikey = s[j];
            HASH_FIND_INT(users,&ikey,tmp);
            if(tmp == NULL)
            {
                return false;
            }
            else
            {
                if(tmp->val <= 0)
                {
                    return false;
                }
                tmp->val--;           
            }       
        }       
    }



    return true;
}