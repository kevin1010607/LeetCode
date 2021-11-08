/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** dfs(int l, int r, int* returnSize, int *dp){
    if(l > r){
        struct TreeNode **ret = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        ret[0] = NULL, *returnSize = 1;
        return ret;
    }
    struct TreeNode **ret = (struct TreeNode**)malloc(dp[r-l+1]*sizeof(struct TreeNode*));
    *returnSize = dp[r-l+1];
    int idx = 0;
    for(int t = l; t <= r; t++){
        int nl, nr;
        struct TreeNode **L = dfs(l, t-1, &nl, dp);
        struct TreeNode **R = dfs(t+1, r, &nr, dp);
        for(int i = 0; i < nl; i++){
            for(int j = 0; j < nr; j++){
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = t, root->left = L[i], root->right = R[j];
                ret[idx++] = root;
            }
        }
        free(L);
        free(R);
    }
    return ret;
}
struct TreeNode** generateTrees(int n, int* returnSize){
    int dp[10];
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = 0;
        for(int j = 0; j < i; j++){
            dp[i] += dp[j]*dp[i-1-j];
        }
    }
    return dfs(1, n, returnSize, dp);
}
