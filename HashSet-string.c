typedef struct _node{
    char *s;
    struct _node *next;
}Node;
typedef struct{
    int cp, size;
    Node **table;
}HashSet;

Node* newNode(const char*, Node*);
void freeNode(Node*);
HashSet* newHashSet(int);
bool empty(HashSet*);
int size(HashSet*);
int getHash(const char*, int);
Node* find(HashSet*, const char*);
void insert(HashSet*, const char*);
void erase(HashSet*, const char*);
void freeHashSet(HashSet*);

Node* newNode(const char *s, Node *next){
    int l = strlen(s);
    Node *res = (Node*)malloc(sizeof(Node));
    res->s = (char*)malloc((l+1)*sizeof(char));
    strncpy(res->s, s, l);
    res->s[l] = '\0';
    res->next = next;
    return res;
}
void freeNode(Node *n){
    free(n->s);
    free(n);
}
HashSet* newHashSet(int cp){
    HashSet *res = (HashSet*)malloc(sizeof(HashSet));
    res->cp = cp, res->size = 0;
    res->table = (Node**)calloc(cp, sizeof(Node*));
    return res;
}
bool empty(HashSet* st){
    return st->size == 0;
}
int size(HashSet* st){
    return st->size;
}
int getHash(const char *s, int size){
    int res = 0;
    for(int i = 0; s[i]; i++) res = (res+s[i])%size;
    return res;
}
Node* find(HashSet *st, const char *s){
    int h = getHash(s, st->cp);
    Node *res = st->table[h];
    while(res){
        if(!strcmp(s, res->s)) return res;
        res = res->next;
    }
    return NULL;
}
void insert(HashSet *st, const char *s){
    int h = getHash(s, st->cp);
    st->table[h] = newNode(s, st->table[h]);
    st->size++;
}
void erase(HashSet *st, const char *s){
    int h = getHash(s, st->cp);
    Node **now = &(st->table[h]);
    while(*now){
        if(!strncmp(s, (*now)->s)){
            Node *tmp = *now;
            *now = (*now)->next;
            freeNode(tmp);
            st->size--;
            break;
        }
        now = &((*now)->next);
    }
}
void freeHashSet(HashSet *st){
    for(int i = 0; i < st->cp; i++){
        while(st->table[i]){
            Node *tmp = st->table[i];
            st->table[i] = tmp->next;
            freeNode(tmp);
        }
    }
    free(st->table);
    free(st);
}
