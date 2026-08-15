struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *invertTree(TreeNode *root)
{
    if(root == nullptr) return;
    TreeNode *lft = root->left;
    TreeNode *rt = root-> right;
    root->left = rt;
    root->right = lft;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}