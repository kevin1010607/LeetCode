/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(a, b) {return a>b?a:b;}
int maxDepth(struct TreeNode* root){
    return root?max(maxDepth(root->left),maxDepth(root->right))+1:0;
}