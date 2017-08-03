#include <iostream>
#include <vector>
#include <queue>
#include "Tree_level_order.h"
using namespace std;
class Solution;


void preorder(TreeNode *node, vector<int> &vec);
void inorder(TreeNode * root, vector<int> &vec);
void print_pre(TreeNode *node);

int main(int argc, char *argv[])
{
    vector<vector<int> > result;
    vector<int> pre,in,post;
    TreeNode *root = new TreeNode(1);
    TreeNode *cur = root;
    cur->left = new TreeNode(3);
    cur->right = new TreeNode(2);
    cur = cur->left;
    cur->right = new TreeNode(2);
    cur = cur->right;
    cur->left = new TreeNode(7);
    cur->right = new TreeNode(9);
    cur = root->right;
    cur->left = new TreeNode(4);

   /* Solution mySol;
    result = mySol.levelOrder(root);
    
    cout << "level order" << endl;
    for (int i = 0 ; i < result.size()  ; i ++){
        for ( int j = 0 ; j < result[i].size() ; j ++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    result = mySol.zigzagLevelOrder(root);
    cout << "zigzag" << endl;
    for (int i = 0 ; i < result.size()  ; i ++){
        for ( int j = 0 ; j < result[i].size() ; j ++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
*/
    

    preorder(root,pre);
    inorder(root,in);

    cur = mySol.buildTree(pre,in);

    print_pre(cur);

    return 0;
}

void preorder(TreeNode *node, vector<int> &vec){     
    if(node){
        cout << node->val <<" ";
        vec.push_back(node->val);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(TreeNode *node, vector<int> &vec){
    if(node){
        inorder(node->left);
        cout << node->val << " ";
        vec.push_back(node->val);
        inorder(node->right);
    }
}

void print_pre(TreeNode *node){
    if(node){
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }
}