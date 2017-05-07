#include <stdio.h>
#include <sdlib.h>
#include <string.h>

int arrayPairSum(int* nums, int numsSize);
int comp(const void *a,const void *b);

int main (void)
{
    int array[4] = {1,4,7,2};
    

}

int comp(const void *a, const void *b)
{
    int c =*(int *)a;
    int d =*(int *)b;
    return (c > d) ? 1 : (c == d) ? 0 : -1;
}

int arrayPairSum(int* nums, int numsSize)
{
    int r = 0;
    int i;
    qsort((void*)nums,numsSize,sizeof(int),comp);

    for ( i = 0 ; i < numsSize ; i+=2 )
    {
        r += nums[i];
    }
    return r;
}
