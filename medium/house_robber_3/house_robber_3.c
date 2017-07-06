#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)


typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}node;

int rob(struct TreeNode *root);
void rob_or_not(struct TreeNode *root , int *rob, int *notRob);

void pre_order(struct TreeNode *root);
void in_order(struct TreeNode *root);
void post_order(struct TreeNode *root);


int main(void){
    node a;
    node *p;
    int sum;
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
    printf("yes man\n");



  
    return 0;
}

int rob(struct TreeNode *root){
    int rob=0 , notRob=0;

    rob_or_not(root,&rob,&notRob);

    return MAX(rob,notRob);
}

void rob_or_not(struct TreeNode *root , int *rob, int *notRob)
{
    int left_child, right_child, n_left_child, n_right_child;
    if (!root) return ;

    left_child = right_child = n_left_child = n_right_child = 0;

    rob_or_not(root->left,&left_child,&n_left_child);
    rob_or_not(root->right,&right_child, &n_right_child);

    *rob = root->val + n_left_child + n_right_child;
    *notRob = MAX(left_child,n_left_child) + MAX(n_right_child,right_child);

}

void pre_order(struct TreeNode* root){

    if(!root) return;
    else{
        printf("%d ",root->val);
        pre_order(root->left);
        pre_order(root->right);
    }

}

void in_order(struct TreeNode* root){
    if (!root) return;
    else{
        in_order(root->left);
        printf("%d ",root->val);
        in_order(root->right);
    }
}

void post_order(struct TreeNode * root){
    if (!root) return ;
    else{
        post_order(root->left);
        post_order(root->right);
        printf("%d ",root->val);
    }
}