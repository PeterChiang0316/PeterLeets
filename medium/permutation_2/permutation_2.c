#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** permute(int* nums, int numsSize, int* returnSize);
void DFS(int depth, int *p, int numsSize, int *ele, int **r);

int visit[100] = {0};
int count = 0;

int main(void)
{
    int a[4] = { 1,3,7,11 };
    int size,i,j;
    int ** b= permute(a,4,&size);

}


int** permute(int* nums, int numsSize, int* returnSize)
{
    int **r;
    int i = numsSize;
    *returnSize =1;
    int p[numsSize];
    memset(visit,0,sizeof(int)*100);
    count = 0;
    while (i)
    {
        (*returnSize) *= i--;
    }
    r = (int **) malloc (sizeof(int *) * (*returnSize));
    for ( i = 0 ; i < (*returnSize) ; i ++ )
    {
        r[i] = (int *)malloc(sizeof(int) * numsSize );
    }

    DFS(0,p,numsSize,nums,r);

    return r;
}

void DFS(int depth,int *p, int numsSize, int *ele,int **r)
{
    unsigned int i ;
    if (depth < numsSize)
    {
        for ( i = 0 ; i < numsSize ; i ++ )
        {
            if (!visit[i])
            {
                if ( ele[i] == ele[i-1] && visit[i-1] && i>0 ) return ;
                //printf("depth :%d , visit :%d\n",depth,ele[i]);
                visit[i] = 1;
                p[depth] = ele[i];
                DFS(depth+1,p,numsSize,ele,r);
                visit[i] = 0;
            }
        }
    
    }

    else {
        for (i = 0 ; i < numsSize ; i ++ )
        {
            printf("%d ",p[i]);

        }
        printf("\n");
        memcpy(r[count++],p,sizeof(int)*numsSize);
    
    }
}

/*void DFS(int depth,int *p, int numsSize, int *ele,int **r)
{
    unsigned int i ;
    unsigned int temp;
    if (depth < numsSize)
    {
        for ( i = depth ; i < numsSize ; i ++ )
        {
                //printf("depth :%d , visit :%d\n",depth,ele[i]);
            temp = ele[depth];
            ele[depth] = ele[i];
            ele[i] = temp;
            p[depth] = ele[depth];
            DFS(depth+1,p,numsSize,ele,r);
//            temp = ele[depth];
//            ele[depth] = ele[i];
//            ele[i] = temp;
        }
    
    }

    else {
        memcpy(r[count++],p,sizeof(int)*numsSize);
        for ( i = 0 ; i < numsSize ; i ++ )
        {
            printf("%d ",p[i]);
        }
        printf("\n");
    }
}*/
