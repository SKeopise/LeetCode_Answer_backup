void reverseString(char* s, int sSize)
{
    char* k;
    int i = 0,j = 0;
    k = s;
    k += sSize-1;
    for(i=0;i<sSize/2;i++)
    {
        j = *s;
        *s = *k;
        *k = j;
        s++;
        k--;
    }

}