#include <stdio.h>
#include <stdlib.h>

#define TAKE 0
#define NOT_TAKE 1
#define MAX(a,b) (a) > (b) ? (a) : (b)

int rob(int* nums, int numsSize);
int rob2(int* nums, int numsSize);

int main(void){

    int nums[4] = {2,1,1,2};

    int sum = rob2(nums,4);

    printf("sum = %d\n",sum);

    return 0;

/*
    Using DP to solve this problem
    Rob(N) = MAX ( Rob(N-1, N-1 Robbed), Rob(N-1, N-1 Not Robbed ) + Rob Nth house )
    By breaking down the problem like above, we can use a array with size = numsSize * 2 as DP table.
    and we calculate the rob or not for each house
    which the row 0 records the money that Robber would have if n th house is robbed
    and row 1 records the money that Robber would have if n th house is not robbed
    so the DP would be
    dp[i][TAKE] = dp[i-1][NOT_TAKE] + nums[i] // if we rob I th house , we can't rob i-1 , so use NOT_TAKE
    dp[i][NOT_TAKE] = max(dp[i-1][TAKE], dp[i-1][NOT_TAKE]) // if we don't rob I th house , we don't care if I-1 is robbed, so just choose the bigger result.

*/


int rob(int * nums , int numsSize ){
    int **dp,i;

    if (!numsSize) return 0;

    dp = (int**)malloc(numsSize * sizeof(int*));
    for ( i = 0 ; i < numsSize ; i ++) dp[i] = (int*) malloc(2 * sizeof(int));

    dp[0][TAKE] = nums[0];
    dp[0][NOT_TAKE] = 0;

    for (i = 1 ; i < numsSize ; i ++ )
    {
        dp[i][TAKE] = dp[i-1][NOT_TAKE] + nums[i];
        dp[i][NOT_TAKE] = MAX(dp[i-1][NOT_TAKE], dp[i-1][TAKE]);
    }

    return MAX(dp[numsSize-1][TAKE], dp[numsSize-1][NOT_TAKE]);
}

/* 
    DP with space improvement , using constant spcae only
*/

int rob2(int *nums , int numsSize){
    int rTake =  nums[0], rNotTake = 0,i,tmp;

    for ( i = 1 ; i < numsSize ; i ++ )
    {
        // use tmp to record the take[N-1]
        tmp = rTake;
        rTake = rNotTake + nums[i];
        rNotTake = MAX(tmp,rNotTake);
    }
    return MAX(rTake, rNotTake);
}

#undef TAKE
#undef NOT_TAKE


