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
public:
    int dfs(TreeNode *root){
        if(!root) return -1;
        int l = dfs(root->left)+1, r = dfs(root->right)+1;
        diameter = max(diameter, l+r);
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root){
        dfs(root);
        return diameter;
    }
private:
    int diameter = 0;
};