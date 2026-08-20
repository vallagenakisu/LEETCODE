#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> inorder(TreeNode *root,vector<int> &v)
{
    if(root == nullptr) return {} ;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
    return v;
}
int kthSmallest(TreeNode* root, int k) 
{
    vector<int> v;
    inorder(root,v);
    // for(auto x : v) cout << x << " ";
    // cout << endl;
    return v[k-1];
}
int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 1;
    cout << kthSmallest(root, k);
}