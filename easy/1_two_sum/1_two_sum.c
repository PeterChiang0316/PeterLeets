#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../data_structure/hash/hash.h"

#define HASHSIZE 4096

int* twoSum(int* nums, int numsSize, int target);
int main (int argc , char *argv[])
{
    int input[27] = {2,7,11,15,128,111111,187877112,9,2,2,2,3,3,1,1,2,2,3,3,4,4,5,5,6,6,77,8};
    int *r;
    r = twoSum(input,27,111113);
    
    free(r);
    return 0;
}

int* twoSum(int* nums, int numsSize, int target)
{
    hashNode* tbl = NULL;
    hashNode* hptr = NULL, *n = NULL;
    int *retV,i,j;
    tbl = (hashNode*) malloc ( HASHSIZE * sizeof(hashNode) );
    memset(tbl,0,HASHSIZE * sizeof(hashNode));
    hptr = tbl;
    retV = (int*) malloc( 2*sizeof(int));

    for ( i = 0 ; i < numsSize ; i ++ ){
       n = findHash(hptr, nums[i], HASHSIZE);
       if ( n != NULL ){ //hash hit 
            retV[0] = n->value;
            retV[1] = i;
            return retV;
       }
       else{
            hashNode newNode;
            newNode.used=1;
            newNode.key=target-nums[i];
            newNode.value=i;
            newNode.next=NULL;
            addToHashTable(hptr, newNode, HASHSIZE);
       }
    }

   return retV;
}

