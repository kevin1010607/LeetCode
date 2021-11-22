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
    TreeNode *buildTree(vector<int>& in, vector<int>& post, int inS, int inE, int postS, int postE, unordered_map<int, int>& m){
        if(inS > inE) return nullptr;
        int idx = m[post[postE]], n = idx-inS;
        TreeNode *root = new TreeNode(post[postE]);
        root->left = buildTree(in, post, inS, idx-1, postS, postS+n-1, m);
        root->right = buildTree(in, post, idx+1, inE, postS+n, postE-1, m);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int, int> m;
        for(int i = 0; i < in.size(); i++) m[in[i]] = i;
        return buildTree(in, post, 0, in.size()-1, 0, post.size()-1, m);
    }
};