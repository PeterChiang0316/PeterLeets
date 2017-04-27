#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x);

int main (void)
{
   printf("%d\n",reverse(-123));    
}

int reverse(int x)
{
    long long r = 0;
    
    while(x!=0)
    {
        r *= 10;
        r += x%10;
        x /= 10;
    }
    return r > INT_MAX ? 0 : r < INT_MIN ? 0 : r;
}
