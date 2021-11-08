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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);

    }
    vector<TreeNode*> dfs(int l, int r){
        if(l > r) return {nullptr};
        vector<TreeNode*> ret;
        for(int i = l; i <= r; i++){
            vector<TreeNode*> L = dfs(l, i-1);
            vector<TreeNode*> R = dfs(i+1, r);
            for(TreeNode *lt : L){
                for(TreeNode *rt : R){
                    ret.push_back(new TreeNode(i, lt, rt));
                }
            }
        }
        return ret;
    }
};