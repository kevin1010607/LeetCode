typedef struct _node{
    int val;
    struct _node *next, *down;
}Node;
typedef struct{
    int level;
    Node *head;
}Skiplist;
Node *newNode(int x, Node *n, Node *d){
    Node *res = (Node*)malloc(sizeof(Node));
    res->val = x, res->next = n, res->down = d;
    return res;
}
Skiplist* skiplistCreate(){
    Skiplist *res = (Skiplist*)malloc(sizeof(Skiplist));
    res->level = 1, res->head = newNode(-1, NULL, NULL);
    return res;
}
bool skiplistSearch(Skiplist* obj, int target){
    for(Node *now = obj->head; now; now = now->down){
        for(; now->next && now->next->val<target; now = now->next);
        if(now->next && now->next->val==target) return true;
    }
    return false;
}
void skiplistAdd(Skiplist* obj, int num){
    int idx = 0;
    Node *v[obj->level];
    for(Node *now = obj->head; now; now = now->down){
        for(; now->next && now->next->val<num; now = now->next);
        v[idx++] = now;
    }
    bool flag = true;
    Node *down = NULL;
    for(int i = idx-1; i>=0 && flag; i--, flag = rand()&1){
        down = v[i]->next = newNode(num, v[i]->next, down);
    }
    if(flag) obj->head = newNode(-1, newNode(num, NULL, down), obj->head), obj->level++;
}
bool skiplistErase(Skiplist* obj, int num){
    bool res = false;
    for(Node *now = obj->head; now; now = now->down){
        for(; now->next && now->next->val<num; now = now->next);
        if(now->next && now->next->val==num){
            res = true;
            Node *tmp = now->next;
            now->next = tmp->next;
            free(tmp);
        }
    }
    return res;
}
void skiplistFree(Skiplist* obj){
    Node *now = obj->head;
    while(now){
        while(now->next){
            Node *tmp = now->next; now->next = tmp->next;
            free(tmp);
        }
        Node *tmp = now; now = now->down;
        free(tmp);
    }
}
/**
 * Your Skiplist struct will be instantiated and called as such:
 * Skiplist* obj = skiplistCreate();
 * bool param_1 = skiplistSearch(obj, target);
 
 * skiplistAdd(obj, num);
 
 * bool param_3 = skiplistErase(obj, num);
 
 * skiplistFree(obj);
*/