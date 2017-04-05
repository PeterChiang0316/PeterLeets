#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s);

int main (int *argc, char *argv[])
{
    int max;
    char *s ="agcbbdefgghhijklmnoppqqqqqq";
    printf("sequence:%s\n",s);
    max = lengthOfLongestSubstring(s);
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

