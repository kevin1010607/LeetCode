/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> path, Ap, Aq;
    void dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root) return;
        path.push_back(root);
        if(root == p) Ap = path;
        if(root == q) Aq = path;
        dfs(root->left, p, q);
        dfs(root->right, p, q);
        path.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        int l = 0, r = min(Ap.size(), Aq.size())-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(Ap[mid] == Aq[mid]) l = mid+1;
            else r = mid-1;
        }
        return Ap[l-1];
    }
};