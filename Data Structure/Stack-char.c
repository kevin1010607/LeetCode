typedef struct{
    char *a;
    int size, cp;
}Stack;

Stack* newStack(int);
void doubleSize(Stack*);
bool empty(Stack*);
bool full(Stack*);
int getSize(Stack*);
char top(Stack*);
void push(Stack*, char);
void pop(Stack*);
void freeStack(Stack*);

Stack* newStack(int cp){
    Stack *res = (Stack*)malloc(sizeof(Stack));
    res->a = (char*)malloc(cp*sizeof(char));
    res->size = 0, res->cp = cp;
    return res;
}
void doubleSize(Stack *s){
    s->cp *= 2;
    s->a = (char*)realloc(s->a, s->cp*sizeof(char));
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
char top(Stack *s){
    return s->a[s->size-1];
}
void push(Stack *s, char c){
    if(full(s)) doubleSize(s);
    s->a[s->size++] = c;
}
void pop(Stack *s){
    if(empty(s)) return;
    s->size--;
}
void freeStack(Stack *s){
    free(s->a);
    free(s);
}
