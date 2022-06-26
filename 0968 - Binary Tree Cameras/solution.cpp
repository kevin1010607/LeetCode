/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int dfs(TreeNode *root, int &res){
        if(!root) return 2;
        int l = dfs(root->left, res), r = dfs(root->right, res);
        if(l==0 || r==0){
            res++;
            return 1;
        }
        return l==1||r==1?2:0;
    }
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        return dfs(root, res)?res:res+1;
    }
};