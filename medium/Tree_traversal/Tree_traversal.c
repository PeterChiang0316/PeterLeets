#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}node;

int* inorderTraversal(struct TreeNode* root, int* returnSize);

void in_order(struct TreeNode* root, int* returnSize, int *result);

void f(struct TreeNode *a);

void stack_enqueue(struct TreeNode* node);
struct TreeNode* stack_dequeue(void);

struct TreeNode *stack[10000];
int top;
int s[10000];

int main(void)
{
    node a;
    node *p;
    int sum,i,*out;
    p = &a;
    a.val = 3;
    a.left = (node*)malloc(sizeof(node));
    p = a.left;
    p->val = 2;
    p->left = NULL;
    p->right = (node *)malloc(sizeof(node));
    p = p->right;
    p->val = 3;
    p->left = NULL;
    p->right = NULL;
    p = &a;
    p->right = (node *)malloc(sizeof(node));
    p = p->right;
    p->val = 3;
    p->left = NULL;
    p->right = (node *)malloc(sizeof(node));
    p = p->right;
    p->val = 1;
    p->left =NULL;
    p->right = NULL;
    out = inorderTraversal(&a,&sum);
    for( i = 0 ; i < sum ; i ++ ){
        printf("%d ",out[i]);
    }
    printf("\n");
    for( i = 0 ; i < sum ; i ++ ){
        printf("%d ",s[i]);
    }
    printf("\n");
    //inorderTraversal(p,&sum);
}



int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *out;
    *returnSize = 0;
    out = (int *)malloc(sizeof(int) * 10000);
    in_order(root, returnSize,out);
    return out;
}

void in_order(struct TreeNode* root, int* returnSize, int *result)
{
    struct TreeNode *iter = root;
    top = -1;
    
    while ( top > -1 || iter){
        if(iter){
            stack_enqueue(iter);
            iter = iter->left;
        }
        else{
            iter = stack_dequeue();
            result[(*returnSize)++] = iter->val;
            iter = iter->right;
        }
    }

}




/*
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *out;
    *returnSize = 0;
    in_order(root, returnSize);
    out = (int *)malloc(sizeof(int) * (*returnSize));
    printf("size :%d\n",*returnSize);
    memcpy(out,s,*returnSize * sizeof(int));
    return out;
}


void in_order(struct TreeNode* root, int* returnSize)
{
    if(!root)return;
    else
    {
        in_order(root->left,returnSize);
        s[(*returnSize)++] = root->val;
        printf("return Size: %d\nval:%d\n",*returnSize,root->val);
        in_order(root->right,returnSize);
    }
}

*/

void pre_order(struct TreeNode* root, int* returnSize){
    if(!root)return;
    else{
        s[(*returnSize)++] = root->val;
        pre_order(root->left, returnSize);
        pre_order(root->right, returnSize);
    }
}

void post_order(struct TreeNode* root, int* returnSize){
    if(!root) return;
    else{
        post_order(root->left, returnSize);
        post_order(root->right, returnSize);
        s[(*returnSize)++] = root->val;
    }
}

void f(struct TreeNode *a){
    if(!a)return;
    else
    {
        f(a->left);
        printf("%d ",a->val);
        f(a->right);
    }
}


void stack_enqueue(struct TreeNode* node)
{
    stack[++top] = node;
}

struct TreeNode* stack_dequeue()
{
    return stack[top--];
}