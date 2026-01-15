#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

void inOrder(TreeNode *Node , vector<int> &visited)
{
    if(Node == nullptr) return;

    inOrder(Node->left , visited);
    visited.push_back(Node->val);
    inOrder(Node->right , visited);
}

//         5
//     1       2
// 4       3
int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(3);
    vector<int> visited;
    inOrder(root , visited);
    for(auto x : visited)
    cout << x << " ";
    cout << visited.size();

}