typedef struct{
    char **a;
    int *ssize, *scp, size, cp;
}Vector;

Vector* newVector(int, int, int, const char*);
void doubleSize(Vector*);
void doubleSSize(Vector*, int);
bool empty(Vector*);
bool emptyS(Vector*, int);
bool full(Vector*);
bool fullS(Vector*, int, int);
int getSize(Vector*);
int getRowSize(Vector*, int);
char** getArray(Vector*);
int* getArraySize(Vector*);
char getElement(Vector*, int, int);
char* getS(Vector*, int);
void modifyByAdd(Vector*, int, int, char);
void modifyByVal(Vector*, int, int, char);
void modifyS(Vector*, int, const char*);
void pushBack(Vector*, const char*);
void pushSBack(Vector*, int, const char*);
void freeVector(Vector*);

Vector* newVector(int size, int cp, int scp, const char *s){
    Vector *res = (Vector*)malloc(sizeof(Vector));
    res->a = (char**)malloc(cp*sizeof(char*));
    res->ssize = (int*)malloc(cp*sizeof(int));
    res->scp = (int*)malloc(cp*sizeof(int));
    res->size = size, res->cp = cp;
    int ssize = strlen(s);
    for(int i = 0; i < cp; i++){
        res->a[i] = (char*)malloc(scp*sizeof(char));
        if(i < size) strncpy(res->a[i], s, ssize);
        res->ssize[i] = i<size?ssize:0;
        res->a[i][res->ssize[i]] = '\0';
        res->scp[i] = scp;
    }
    return res;
}
void doubleSize(Vector *v){
    int n = v->cp*2;
    v->a = (char**)realloc(v->a, n*sizeof(char*));
    v->ssize = (int*)realloc(v->ssize, n*sizeof(int));
    v->scp = (int*)realloc(v->scp, n*sizeof(int));
    for(int i = v->cp; i < n; i++){
        v->a[i] = (char*)malloc(v->scp[0]*sizeof(char));
        v->ssize[i] = 0, v->scp[i] = v->scp[0];
        v->a[i][v->ssize[i]] = '\0';
    }
    v->cp = n;
}
void doubleSSize(Vector *v, int id){
    v->scp[id] *= 2;
    v->a[id] = (char*)realloc(v->a[id], v->scp[id]*sizeof(char));
}
bool empty(Vector *v){
    return v->size==0;
}
bool emptyS(Vector *v, int id){
    return v->ssize[id]==0;
}
bool full(Vector *v){
    return v->size==v->cp;
}
bool fullS(Vector *v, int id, int len){
    return v->ssize[id]+len+1>v->scp[id];
}
int getSize(Vector *v){
    return v->size;
}
int getSSize(Vector *v, int id){
    return v->ssize[id];
}
char** getArray(Vector *v){
    return v->a;
}
int* getArraySize(Vector *v){
    return v->ssize;
}
char getElement(Vector *v, int id, int c){
    return v->a[id][c];
}
char* getS(Vector *v, int id){
    return v->a[id];
}
void modifyByAdd(Vector *v, int id, int c, char dval){
    v->a[id][c] += dval;
}
void modifyByVal(Vector *v, int id, int c, char val){
    v->a[id][c] = val;
}
void modifyS(Vector *v, int id, const char *s){
    int len = strlen(s);
    v->ssize[id] = 0;
    while(fullS(v, id, len)) doubleSSize(v, id);
    strncpy(v->a[id], s, len);
    v->ssize[id] = len;
    v->a[id][v->ssize[id]] = '\0';
}
void pushBack(Vector *v, const char *s){
    if(full(v)) doubleSize(v);
    v->size++;
    int len = strlen(s), id = v->size-1;
    while(fullS(v, id, len)) doubleSSize(v, id);
    strncpy(v->a[id], s, len);
    v->ssize[id] = len;
    v->a[id][v->ssize[id]] = '\0';
}
void pushSBack(Vector *v, int id, const char *s){
    int len = strlen(s);
    while(fullS(v, id, len)) doubleSSize(v, id);
    strncpy(v->a[id]+v->ssize[id], s, len);
    v->ssize[id] += len;
    v->a[id][v->ssize[id]] = '\0';
}
void freeVector(Vector *v){
    for(int i = 0; i < v->cp; i++) free(v->a[i]);
    free(v->a);
    free(v->ssize);
    free(v->scp);
    free(v);
}
