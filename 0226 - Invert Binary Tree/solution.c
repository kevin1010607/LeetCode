/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root) return NULL;
    struct TreeNode *l = invertTree(root->left);
    struct TreeNode *r = invertTree(root->right);
    root->left = r, root->right = l;
    return root;
}