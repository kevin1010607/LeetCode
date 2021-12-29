/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node *findNext(Node *root){
        if(!root) return nullptr;
        if(root->left) return root->left;
        else if(root->right) return root->right;
        else return findNext(root->next);
    }
    Node* connect(Node *root){
        if(!root) return nullptr;
        if(root->left) root->left->next = root->right?root->right:findNext(root->next);
        if(root->right) root->right->next = findNext(root->next);
        connect(root->right);
        connect(root->left);
        return root;
    }
};