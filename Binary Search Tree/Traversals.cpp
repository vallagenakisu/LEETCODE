#include <bits/stdc++.h>
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
void preOrder(TreeNode *Node , vector<int> &visited){
    if(Node == nullptr) return ;
    visited.push_back(Node->val);
    preOrder(Node->left , visited);
    preOrder(Node->right , visited);
}
void postOrder(TreeNode *Node , vector<int> &visited){
    if(Node == nullptr) return;
    postOrder(Node->left, visited);
    postOrder(Node->right, visited);
    visited.push_back(Node->val);
}
vector<vector<int>> levelOrder(TreeNode *Node )
{
    if(Node == nullptr) return{};
    queue<TreeNode*> q;
    q.push(Node);
    vector<vector<int>> result;
    int level = 0 ;
    while(!q.empty()){
        int len = q.size();
        vector<int> vec;
        for(int i = 0 ; i < len ; i++)
        {
            TreeNode* root = q.front();
            q.pop();
            vec.push_back(root->val);
            if(root->left != nullptr) q.push(root->left);
            if(root->right != nullptr) q.push(root->right);
        }
        result.push_back(vec);
        level++;
    }
    return result;
}
int main()
{
    // Example tree (6 levels):
    //              10
    //          /       \
    //        5          15
    //      /   \      /    \
    //     3     7   12     18
    //    / \   / \  / \    / \
    //   1  4  6  8 11 13  16 20
    //  /                \
    // 0                 17

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(8);

    root->right->left->left = new TreeNode(11);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(16);
    root->right->right->right = new TreeNode(20);

    root->left->left->left->left = new TreeNode(0);
    root->right->right->left->right = new TreeNode(17);

    vector<int> inorder, preorder , postorder;
    inOrder(root, inorder);
    preOrder(root, preorder);
    postOrder(root , postorder);

    cout << "InOrder: ";
    for (int x : inorder) cout << x << " ";
    cout << endl;

    cout << "PreOrder: ";
    for (int x : preorder) cout << x << " ";
    cout << endl;

    cout << "PostOrder: ";
    for (int x : postorder) cout << x << " ";
    cout << endl;

    cout << "LevelOrder:" << endl;
    vector<vector<int>> result = levelOrder(root);
    for(auto x : result){
        for(auto y: x){
            cout << y<<" ";
        }
        cout << endl;
    }
}