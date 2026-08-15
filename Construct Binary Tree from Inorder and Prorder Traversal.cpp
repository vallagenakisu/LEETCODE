#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int pi ;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* array2tree(vector<int>&preorder,int left, int right)
{
    if(left > right) return nullptr;
    int root_val = preorder[pi++];
    TreeNode* root = new TreeNode(root_val);
    
    int root_index = mp[root_val];
    root->left = array2tree(preorder,left,root_index-1);
    root->right = array2tree(preorder,root_index+1,right);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    pi = 0;
    for(int i = 0 ; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    return array2tree(preorder,0,inorder.size()-1);
}
int main()
{
}