/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
struct Node* findNext(struct Node *root){
    if(!root) return NULL;
    if(root->left) return root->left;
    else if(root->right) return root->right;
    else return findNext(root->next);
}
struct Node* connect(struct Node *root){
	if(!root) return NULL;
    if(root->left) root->left->next = root->right?root->right:findNext(root->next);
    if(root->right) root->right->next = findNext(root->next);
    connect(root->right);
    connect(root->left);
    return root;
}