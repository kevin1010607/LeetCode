/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {return a>b?a:b;}
int min(int a, int b) {return a<b?a:b;}
int maxDiff(struct TreeNode *root, int ma, int mi){
    if(!root) return ma-mi;
    return max(maxDiff(root->left, max(ma, root->val), min(mi, root->val)),
              maxDiff(root->right, max(ma, root->val), min(mi, root->val)));
}
int maxAncestorDiff(struct TreeNode* root){
    return maxDiff(root, root->val, root->val);
}