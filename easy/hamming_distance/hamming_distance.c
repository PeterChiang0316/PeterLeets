#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hammingDistance(int x, int y) ;

int main(void)
{
    int a = 4, b= 67;
    int c = hammingDistance(a,b);
    printf("%d\n",c);
}

int hammingDistance(int x, int y) {
   int r = x ^ y;
   int d = 0;
   
   while ( r > 0 )
   {
        d++;
        r/=2;
   }
   return d;
}
