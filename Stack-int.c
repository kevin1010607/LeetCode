typedef struct{
    int *a, size, cp;
}Stack;

Stack* newStack(int);
void doubleSize(Stack*);
bool empty(Stack*);
bool full(Stack*);
int getSize(Stack*);
int top(Stack*);
void push(Stack*, int);
void pop(Stack*);
void freeStack(Stack*);

Stack* newStack(int cp){
    Stack *res = (Stack*)malloc(sizeof(Stack));
    res->a = (int*)malloc(cp*sizeof(int));
    res->size = 0, res->cp = cp;
    return res;
}
void doubleSize(Stack *s){
    s->cp *= 2;
    s->a = (int*)realloc(s->a, s->cp*sizeof(int));
}
bool empty(Stack *s){
    return s->size==0;
}
bool full(Stack *s){
    return s->size==s->cp;
}
int getSize(Stack *s){
    return s->size;
}
int top(Stack *s){
    return s->a[s->size-1];
}
void push(Stack *s, int val){
    if(full(s)) doubleSize(s);
    s->a[s->size++] = val;
}
void pop(Stack *s){
    if(empty(s)) return;
    s->size--;
}
void freeStack(Stack *s){
    free(s->a);
    free(s);
}
