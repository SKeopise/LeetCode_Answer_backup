int strStr(char* haystack, char* needle) {

    int i = 0, j = 0;
    int cnt = 0;
    int buf = 0;
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    while (j < len2 && i < len1)
    {
        if (haystack[i] != needle[j])
        {
            if (buf > 0)
            {
                j = 0;
                i -= buf;
                buf = 0;
            }
            i++;
            continue;
        }
        else
        {
            if (j == 0)
            {
                cnt = i;
            }
            i++;
            j++;

            buf++;
        }

    }

    if (j >= len2)
    {
        return cnt;
    }


    return -1;

}