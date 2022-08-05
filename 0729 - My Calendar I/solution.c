typedef struct _node{
    int s, e;
    struct _node *left, *right;
} Node;

Node *newNode(int s, int e){
    Node *res = (Node*)malloc(sizeof(Node));
    res->s = s, res->e = e, res->left = NULL, res->right = NULL;
    return res;
}

bool insertNode(int s, int e, Node **root){
    if(!*root){
        *root = newNode(s, e);
        return true;
    }
    if(e <= (*root)->s) return insertNode(s, e, &((*root)->left));
    if(s >= (*root)->e) return insertNode(s, e, &((*root)->right));
    return false;
}

void freeNode(Node *root){
    if(!root) return;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}

typedef struct {
    Node *root;
} MyCalendar;

MyCalendar* myCalendarCreate() {
    MyCalendar *res = (MyCalendar*)malloc(sizeof(MyCalendar));
    res->root = NULL;
    return res;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    return insertNode(start, end, &(obj->root));
}

void myCalendarFree(MyCalendar* obj) {
    freeNode(obj->root);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/