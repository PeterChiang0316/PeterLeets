#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int idx[10] = {0,2,6,7,8,3,4,5,1,9};
unsigned int pivot[10] = {0,1,2,0,2,0,3,0,0,1};
char map[10][6] = { "zero", "two", "six", "seven", "eight", "three", "four", "five", "one", "nine" };
char* originalDigits(char *s);

int main (void)
{
    char s[50000] = "thrtwotwotwotwoeethreefourfourfivesevensevensevenninenineninenine";
    char *a = originalDigits(s);
    printf ("a : %s\n", a );
    return 0;
}

char* originalDigits(char *s)
{
    unsigned int o_len = strlen(s);
    unsigned int number[27] = {0};
    unsigned int result[10] = {0};
    unsigned int i,j,k;
    char *c;
    
    //return buffer of output
    c = (char *)malloc(sizeof(char) * 10000);
    
    //store every english letter to buffer , using ascii code minus 'a' as index (0~26)
    for (i = 0 ; i < o_len ; i++)
    {
        number[s[i]-'a']++;
    }
    
    for (i = 0 ; i < 26; i++ )
    {
        printf("number[%c] = %d\n",i+'a',number[i]);
    }

    //use a pre-defined sequency to idenetify the number of every digit
    // [0,2,6,7,9,8,3,4,5,1]

    for (i = 0 ; i < 10 ; i ++ )
    {
        unsigned int pivot_len;
        // pivot means the digit used to identify in this round
        pivot_len = strlen(map[i]);
        printf("pivot %s, pivot_len = %d\n",map[i],pivot_len);
        //add the number of digit to the result, result should be traversed only once in this for-loop
        //weight means how many same english letter in the pivot 
        result[idx[i]] = number[map[i][pivot[i]]-'a'];
        printf("result[%d] += %d\n", idx[i] ,number[map[i][pivot[i]]-'a']);
        
        // below for-loop subtract all the letters of pivot from the letter pool 
        for ( j = 0 ; j < pivot_len ; j ++ )
        {
            printf("subtract %c from pool with %d\n",map[i][j],result[idx[i]]);
            number[map[i][j]-'a']-= result[idx[i]];
        }
        
    }

    k = 0;
    for ( i = 0 ; i < 10 ; i ++ )
    {
        for ( j = 0 ; j < result[i] ; j ++ )
        {
            c[k++] = i + '0';
        }
    }
    c[k] = '\0';
    return c;
   
}

