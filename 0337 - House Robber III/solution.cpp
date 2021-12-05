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
    pair<int, int> solve(TreeNode *root){
        if(!root) return {0, 0};
        pair<int, int> l = solve(root->left), r = solve(root->right), res;
        res.first = root->val+l.second+r.second;
        res.second = max(l.first, l.second)+max(r.first, r.second);
        return res;
    }
    int rob(TreeNode* root) {
        pair<int, int> res = solve(root);
        return max(res.first, res.second);
    }
};