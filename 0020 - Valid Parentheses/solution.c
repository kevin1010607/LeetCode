typedef struct{
    char *a;
    int size, cp;
}Stack;
Stack* newStack(){
    Stack *res = (Stack*)malloc(sizeof(Stack));
    res->a = (char*)malloc(1000*sizeof(char));
    res->size = 0, res->cp = 1000;
    return res;
}
void doubleSize(Stack *s){
    int n = s->cp*2;
    char *c = (char*)malloc(n*sizeof(char));
    memcpy(c, s->a, s->size*sizeof(char));
    free(s->a);
    s->a = c, s->cp = n;
}
void push(Stack *s, char c){
    if(s->size == s->cp) doubleSize(s);
    s->a[s->size++] = c;
}
void pop(Stack *s){
    if(s->size == 0) return;
    s->size--;
}
char top(Stack *s) {return s->a[s->size-1];}
int getSize(Stack *s) {return s->size;}
void freeStack(Stack *s) {free(s->a), free(s);}
bool isValid(char * s){
    Stack *sk = newStack();
    for(int i = 0; s[i]; i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{') push(sk, s[i]);
        else{
            if(getSize(sk)==0 || !(s[i]-top(sk)==1||s[i]-top(sk)==2)) return false;
            pop(sk);
        }
    }
    bool res = getSize(sk)==0;
    freeStack(sk);
    return res;
}