typedef struct{
    int *a, size, cp;
}Vector;

Vector* newVector(int, int, int);
void doubleSize(Vector*);
bool empty(Vector*);
bool full(Vector*);
int getSize(Vector*);
int* getArray(Vector*);
int getElement(Vector*, int);
void modifyByAdd(Vector*, int, int);
void modifyByVal(Vector*, int, int);
void pushBack(Vector*, int);
void popBack(Vector*);
void freeVector(Vector*);

Vector* newVector(int size, int cp, int val){
    Vector *res = (Vector*)malloc(sizeof(Vector));
    res->a = (int*)malloc(cp*sizeof(int));
    res->size = size, res->cp = cp;
    for(int i = 0; i < size; i++) res->a[i] = val;
    return res;
}
void doubleSize(Vector *v){
    v->cp *= 2;
    v->a = (int*)realloc(v->a, v->cp*sizeof(int));
}
bool empty(Vector *v){
    return v->size==0;
}
bool full(Vector *v){
    return v->size==v->cp;
}
int getSize(Vector *v){
    return v->size;
}
int* getArray(Vector *v){
    return v->a;
}
int getElement(Vector *v, int id){
    return v->a[id];
}
void modifyByAdd(Vector *v, int id, int dval){
    v->a[id] += dval;
}
void modifyByVal(Vector *v, int id, int val){
    v->a[id] = val;
}
void pushBack(Vector *v, int val){
    if(full(v)) doubleSize_Vector(v);
    v->a[v->size++] = val;
}
void popBack(Vector *v){
    if(empty(v)) return;
    v->size--;
}
void freeVector(Vector *v){
    free(v->a);
    free(v);
}
