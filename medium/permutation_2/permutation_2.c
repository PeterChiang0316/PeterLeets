#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** permute(int* nums, int numsSize, int* returnSize);
void DFS(int depth, int *p, int numsSize, int *ele, int **r, int *returnSize);
int comp(const void *a, const void *b);

int visit[100] = {0};
int count = 0;

int main(void)
{
    int a[4] = { 1,7,7,11 };
    int size,i,j;
    int ** b= permute(a,4,&size);

}

int comp(const void *a, const void *b)
{
    int c = *(int*)a;
    int d = *(int*)b;

    return (c > d)? 1 : (c < d)? -1 : 0;
}

int** permute(int* nums, int numsSize, int* returnSize)
{
    int **r;
    int i = numsSize;
    int j = 0;
    *returnSize =1;
    int p[numsSize];
    int dependence[numsSize];
    memset(visit,0,sizeof(int)*100);
    count = 0;
    qsort((void*)nums,numsSize,sizeof(int),comp);
    while (i)
    {
        (*returnSize) *= i--;
    }
    r = (int **) malloc (sizeof(int *) * (*returnSize));
    for ( i = 0 ; i < (*returnSize) ; i ++ )
    {
        r[i] = (int *)malloc(sizeof(int) * numsSize );
    }
    *returnSize = 0;
    DFS(0,p,numsSize,nums,r,returnSize);

    return r;
}
void DFS(int depth,int *p, int numsSize, int *ele,int **r, int *returnSize)
{
    unsigned int i ;
    unsigned int temp;
    if (depth < numsSize)
    {
        for ( i = depth ; i < numsSize ; i ++ )
        {
                //printf("depth :%d , visit :%d\n",depth,ele[i]);
            if ( ele[depth] == ele[i] && depth != i ) continue;
            temp = ele[depth];
            ele[depth] = ele[i];
            ele[i] = temp;
            p[depth] = ele[depth];
            DFS(depth+1,p,numsSize,ele,r, returnSize);
        }
    
    }

    else {
        memcpy(r[(*returnSize)++],p,sizeof(int)*numsSize);
        for ( i = 0 ; i < numsSize ; i ++ )
        {
            printf("%d ",p[i]);
        }
        printf("\n");
    }
}
