typedef struct{
    char *a; 
    int size, cp;
}String;

String* newString(int, const char*);
void doubleSize(String*);
bool empty(String*);
bool full(String*, int);
int getSize(String*);
char getElement(String*, int);
char* getS(String*);
void modifyByAdd(String*, int, char);
void modifyByVal(String*, int, char);
void modifyS(String*, const char*);
void pushSBack(String*, const char*);
void pushBack(String*, char);
void popBack(String*);
void freeString(String*);

String* newString(int cp, const char *s){
    String *res = (String*)malloc(sizeof(String));
    res->a = (char*)malloc(cp*sizeof(char));
    int size = strlen(s);
    strncpy(res->a, s, size);
    res->a[size] = '\0';
    res->size = size, res->cp = cp;
    return res;
}
void doubleSize(String *v){
    v->cp *= 2;
    v->a = (char*)realloc(v->a, v->cp*sizeof(char));
}
bool empty(String *s){
    return s->size==0;
}
bool full(String *s, int len){
    return s->size+len+1>s->cp;
}
int getSize(String *s){
    return s->size;
}
char getElement(String *s, int id){
    return s->a[id];
}
char* getS(String *s){
    return s->a;
}
void modifyByAdd(String *s, int id, char dval){
    s->a[id] += dval;
}
void modifyByVal(String *s, int id, char val){
    s->a[id] = val;
}
void modifyS(String *s, const char *val){
    int len = strlen(val);
    s->size = 0;
    while(full(s, len)) doubleSize(s);
    strncpy(s->a, val, len);
    s->size = len;
    s->a[s->size] = '\0';
}
void pushSBack(String *s, const char *val){
    int len = strlen(val);
    while(full(s, len)) doubleSize(s);
    strncpy(s->a+s->size, val, len);
    s->size += len;
    s->a[s->size] = '\0';
}
void pushBack(String *s, char val){
    if(full(s, 1)) doubleSize(s);
    s->a[s->size++] = val;
    s->a[s->size] = '\0';
}
void popBack(String *s){
    if(empty(s)) return;
    s->a[--s->size] = '\0';
}
void freeString(String *s){
    free(s->a);
    free(s);
}

char * removeKdigits(char * num, int k){
    String *s = newString(105, "");
    for(int i = 0; num[i]; i++){
        while(k && !empty(s) && getElement(s, getSize(s)-1)>num[i]) popBack(s), k--;
        if(!empty(s) || num[i]!='0') pushBack(s, num[i]);
    }
    while(!empty(s) && k--) popBack(s);
    char *res = getS(s);
    // freeString(s);
    return empty(s)?"0":res;
}