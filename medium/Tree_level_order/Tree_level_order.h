#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*>nodeQ;
        //vector<TreeNode*> nodeQ(20,NULL);
        vector<vector<int> > result;
        result.reserve(10);
        int i;
        TreeNode * begin = NULL, *end = NULL, *cur = NULL;
        unsigned int pop_index; // to record the index need to pop in each round
        cur = root;
        if(cur)nodeQ.push(root);
        pop_index = nodeQ.size();
        while (!nodeQ.empty())
        {
            vector<int> row;
            row.reserve(10);
            for ( i = 0 ; i < pop_index ; i ++)
            {   
               
                cur = nodeQ.front();
                if(cur->left)nodeQ.push(cur->left);
                if(cur->right)nodeQ.push(cur->right);
                row.push_back(cur->val);
                nodeQ.pop();
            }
            result.push_back(row);
            cout << endl;
            pop_index = nodeQ.size();
        }
        return result;
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*>nodeQ;
        //vector<TreeNode*> nodeQ(20,NULL);
        vector<vector<int> > result;
        result.reserve(10);
        int i;
        bool isEven = false;
        TreeNode *cur = NULL;
        unsigned int pop_index; // to record the index need to pop in each round
        cur = root;
        if(cur)nodeQ.push_back(root);
        pop_index = nodeQ.size();
        while (!nodeQ.empty() )
        {
            vector<int> row;
            row.reserve(10);
            for ( i = 0 ; i < pop_index ; i ++)
            {   
                if( isEven ){
                    cur = nodeQ.back();
                    nodeQ.pop_back();
                    if(cur->right)nodeQ.push_front(cur->right);
                    if(cur->left)nodeQ.push_front(cur->left);
                    //nodeQ.pop_front();
                }
                else{
                    cur = nodeQ.front();
                    nodeQ.pop_front();
                    if(cur->left)nodeQ.push_back(cur->left);
                    if(cur->right)nodeQ.push_back(cur->right);
                    //if(cur->right)nodeQ.push_back(cur->right);
                    //if(cur->left)nodeQ.push_back(cur->left);
                    //nodeQ.pop_back();
                }
                //if(cur->right)nodeQ.push_back(cur->right);
                //if(cur->left)nodeQ.push_back(cur->left);
                row.push_back(cur->val);
                //if( (j&1) )nodeQ.pop_front();
                //else nodeQ.erase(nodeQ.begin()+(pop_index-1-i));
                
            }
            result.push_back(row);
            pop_index = nodeQ.size();
            isEven = !isEven;
            //if(j > 3 ) j = 0;
        }
        return result;
    }
/*        
        queue<TreeNode*>nodeQ;
        //vector<TreeNode*> nodeQ(20,NULL);
        vector<vector<int> > result;
        result.reserve(10);
        int i,j = 0;
        TreeNode * begin = NULL, *end = NULL, *cur = NULL;
        unsigned int pop_index; // to record the index need to pop in each round
        cur = root;
        if(cur)nodeQ.push(root);
        pop_index = nodeQ.size();
        while (!nodeQ.empty())
        {
            vector<int> row;
            row.reserve(10);
            for ( i = 0 ; i < pop_index ; i ++)
            {   
               
                cur = nodeQ.front();
                if(cur->left)nodeQ.push(cur->left);
                if(cur->right)nodeQ.push(cur->right);
                row.push_back(cur->val);
                nodeQ.pop();
            }
            if( (j&1) )reverse(row.begin(),row.end() );
            result.push_back(row);
            pop_index = nodeQ.size();
            j++;
        }
        return result;
    }
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *cur = NULL, *root = NULL;
        vector<int>::iterator it;
        unsigned int left, right;
        if(preorder.empty()) return NULL;

        root = new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        it = find(inorder.begin(),inorder.end(), root->val);
        left = distance(inorder.begin(),it);
        right = left;
        left--;
        right++;
        root->left = MakeTree(preorder, inorder, 0, left);
        root->right = MakeTree(preorder, inorder, right, inorder.size()-1 );

        return root;
    

    }

    TreeNode* MakeTree(vector<int>& preorder, vector<int> &inorder, unsigned int left, unsigned int right){
        TreeNode *root = NULL;

        if(preorder.empty()) return NULL;

        root = new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        root->left = MakeTree(preorder,new vector<int>(inorder.begin(), (find(inorder.begin(),inorder.end(),root->val)-1));
        root->right = MakeTree(preorder,new vector<int>( (find(inorder.begin(),inorder.end(),root->val)+1), inorder.end() ));
        
        return root;
        
    }

};