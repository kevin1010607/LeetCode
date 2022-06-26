/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root, int *res){
    if(!root) return 2;
    int l = dfs(root->left, res), r = dfs(root->right, res);
    if(l==0 || r==0){
        ++*res;
        return 1;
    }
    return l==1||r==1?2:0;
}
int minCameraCover(struct TreeNode* root){
    int res = 0;
    return dfs(root, &res)?res:res+1;
}