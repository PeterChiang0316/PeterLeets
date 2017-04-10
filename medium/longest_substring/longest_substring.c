#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s);

int main (int *argc, char *argv[])
{
    int max;
    //char *s ="agcbbdefgghhijklmnoppqqqqqq";
    char *s ="a";
    printf("sequence:%s\n",s);
    max = lengthOfLongestSubstring2(s);
    printf("max :%d\n",max);
    return 0;
}

int lengthOfLongestSubstring(char* s)
{
    int tbl[100] = {0};
    int occur[100] = {0};
    int i = 0,j = 0, round = 1;
    int length = 0 , max = 0;

    if (!s) return 0;
    if (*s == '\0') return 0;

    do{
        if (tbl[(*s)-' '] != round)
        {
            tbl[(*s)-' '] = round;
            occur[(*s)-' '] = j;
            length++;
            max = length > max ? length : max;
            j++;
            printf("add it to sequence length %d,i:%d,j:%d\n",length,i,j);
            s++;
        }
        else //hit the last word of substring
        {
            max = length > max ? length : max;
            printf("hit the last word %d,i:%d,j:%d\n",length,i,j);
            length = 0;
            round ++;
            s -= j-occur[(*s)-' ']-1;
            printf("s back to %c\n",*s);
            i = occur[(*s)-' ']+1;
            j = i;
            
        }

        
    }
    while ((*s)!='\0');
        
    
    
    return max;
}

int lengthOfLongestSubstring2(char *s)
{
    unsigned int len = strlen(s);
    int tbl[100] = {-1};
    int i = -1, j = 0, round = 1;
    int max = 0;

    for ( j = 0 ; j < 100 ; j ++) printf("%d ",tbl[j] );
    //char *s ="agcbbdefgghhijklmnoppqqqqqq";
    printf("len :%d\n",len);
    for ( j = 0 ; j < len ; j ++ )
    {
        printf("index : %d\ntbl[a]=%d\n",s[j]-' ',tbl[s[j]-' ']);
        if (tbl[s[j]-' '] > i) i = tbl[s[j]-' '];
        max = (j-i) > max ? (j-i) : max;
        tbl[s[j]-' '] = j;
        printf("j-tbl[s[%c]-' ']+1 = %d\n",s[j], j-tbl[s[j]-' '] + 1);
        printf("after tbl[%c] = %d\n",s[j],j);
        printf("[i,j] = [%d,%d]\n",i,j);
        printf("s[j] = %c\n",s[j]);

    }

    return max;
}

