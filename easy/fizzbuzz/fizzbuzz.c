#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize);

int main (void)
{
    char ** a;
    int size,i;
    a = fizzBuzz(1,&size);

    for (i = 0 ; i < size ; i ++ )
    {
        printf("%s\n",a[i]);
    }
}

char** fizzBuzz(int n, int* returnSize)
{
    char **r;
    r = (char **)malloc(sizeof(char *) * n); //char pointer array
    int i,len;
    char buf[20];
    for( i = 1 ; i <= n ; i ++ )
    {
        memset(buf,0,20);
        if( i%3 == 0 )
        {
            strcat(buf,"Fizz");
        }
        if( i%5 == 0 )
        {
            strcat(buf,"Buzz");
        }
        len = strlen(buf);
        //printf("before len = %d\n",len);
        if (len > 0){
            r[i-1] = (char *)malloc(sizeof(char) * (len+1));
            memcpy(r[i-1],buf,len+1);
          //  printf("r[%d]=%s",i-1,r[i-1]);
            continue;
        }
    
        sprintf(buf,"%d",i);
        len = strlen(buf);
        //printf("after len = %d\n",len);
        //printf("buf : %s\n",buf);
        r[i-1] = (char *)malloc(sizeof(char) * (len+1));
        memcpy(r[i-1],buf,len+1);
        //printf("r[%d] : %s\n",i-1,r[i-1]);

    }
    *returnSize = n;
    return r;
}
