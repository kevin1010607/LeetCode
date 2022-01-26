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
int find(struct TreeNode** now, bool ret){
    while(*now){
        if(!(*now)->left){
            if(ret) return (*now)->val;
            *now = (*now)->right;
            return INT_MAX;
        }
        else{
            struct TreeNode *tmp = (*now)->left;
            while(tmp->right && tmp->right!=*now) tmp = tmp->right;
            if(tmp->right){
                if(ret) return (*now)->val;
                tmp->right = NULL;
                *now = (*now)->right;
                return INT_MAX;
            }
            else{
                tmp->right = *now;
                *now = (*now)->left;
            }
        }
    }
    *now = NULL;
    return INT_MAX;
}
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int *res = (int*)malloc(10000*sizeof(int)), idx = 0;
    while(root1 || root2){
        int n1 = find(&root1, true), n2 = find(&root2, true);
        if(n1 < n2){
            res[idx++] = n1;
            find(&root1, false);
        }
        else{
            res[idx++] = n2;
            find(&root2, false);
        }
    }
    *returnSize = idx;
    return res;
}