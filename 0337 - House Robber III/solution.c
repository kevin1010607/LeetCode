/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {return a>b?a:b;}
typedef struct{int v1, v2;} S;
S solve(struct TreeNode* root){
    S res = {0, 0};
    if(!root) return res;
    S l = solve(root->left), r = solve(root->right);
    res.v1 = root->val+l.v2+r.v2;
    res.v2 = max(l.v1, l.v2)+max(r.v1, r.v2);
    return res;
}
int rob(struct TreeNode* root){
    S res = solve(root);
    return max(res.v1, res.v2);
}