bool isPalindrome(char * s){

    int i,j;

    i = 0;
    j = strlen(s)-1;
    
    if(j == 0)
    {
        return true;
    }

    while(i<strlen(s) && j>0)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i] += 32;
            }
        }   
        else
        {
            i++;
            continue;
        } 

        if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j] >= '0' && s[j] <= '9'))
        {
            if(s[j]>='A' && s[j]<='Z')
            {
                s[j] += 32;
            }
        }   
        else
        {
            j--;
            continue;
        }      


        if(s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
            if( i > j )
            {
                return true;
            }               
        }    

    }
    
    
    return true;
}