#include <stdio.h>
#include <stdlib.h>

#define TAKE 0
#define NOT_TAKE 1
#define MAX(a,b) (a) > (b) ? (a) : (b)

int rob(int* nums, int numsSize);
int rob2(int *nums , int numsSize);

int main(void){

    int a[6] = {2,2,4,3,2,5};

    int sum = rob(a,6);

    return 0;
}

int rob(int *nums, int numsSize){
    //Below decide whether to rob the Nth house.
    int a = rob2(&nums[0],numsSize-1);
    int b = rob2(&nums[1],numsSize-1);
    return MAX( rob2(&nums[0],numsSize-1),rob2(&nums[1], numsSize-1));
}


int rob2(int *nums , int numsSize){
    int rTake =  *nums, rNotTake = 0,i,tmp;

    for ( i = 1 ; i < numsSize ; i ++ )
    {
        // use tmp to record the take[N-1]
        tmp = rTake;
        rTake = rNotTake + *(nums+i);
        rNotTake = MAX(tmp,rNotTake);
    }

    return MAX(rTake, rNotTake);
}
