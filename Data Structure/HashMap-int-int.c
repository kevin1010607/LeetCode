typedef struct _node{
    int key, val;
    struct _node *next;
}Node;
typedef struct{
    int size;
    Node **table;
}HashMap;

Node* newNode(int, int, Node*);
HashMap* newHashMap(int);
Node* find(HashMap*, int);
void insert(HashMap*, int, int);
int getVal(HashMap*, int);
void modifyByAdd(HashMap*, int, int);
void modifyByVal(HashMap*, int, int);
void freeHashMap(HashMap*);

Node* newNode(int key, int val, Node *next){
    Node *res = (Node*)malloc(sizeof(Node));
    res->key = key, res->val = val, res->next = next;
    return res;
}
HashMap* newHashMap(int size){
    HashMap *res = (HashMap*)malloc(sizeof(HashMap));
    res->size = size;
    res->table = (Node**)calloc(size, sizeof(Node*));
    return res;
}
Node* find(HashMap *m, int key){
    int h = abs(key)%m->size;
    Node *res = m->table[h];
    while(res){
        if(res->key == key) return res;
        res = res->next;
    }
    return NULL;
}
void insert(HashMap *m, int key, int val){
    int h = abs(key)%m->size;
    m->table[h] = newNode(key, val, m->table[h]);
}
int getVal(HashMap *m, int key){
    Node *res = find(m, key);
    if(res) return res->val;
    insert(m, key, 0);
    return 0;
}
void modifyByAdd(HashMap *m, int key, int dval){
    Node *res = find(m, key);
    if(res) res->val += dval;
    else insert(m, key, dval);
}
void modifyByVal(HashMap *m, int key, int val){
    Node *res = find(m, key);
    if(res) res->val = val;
    else insert(m, key, val);
}
void freeHashMap(HashMap *m){
    for(int i = 0; i < m->size; i++){
        while(m->table[i]){
            Node *tmp = m->table[i];
            m->table[i] = tmp->next;
            free(tmp);
        }
    }
    free(m->table);
    free(m);
}
