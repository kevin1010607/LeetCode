typedef struct {
    int *a, front, rear, cp;
}Deque;

Deque* newDeque(int);
void doubleSize(Deque*);
bool full(Deque*);
bool empty(Deque*);
void pushBack(Deque*, int);
void pushFront(Deque*, int);
void popBack(Deque*);
void popFront(Deque*);
int front(Deque*);
int back(Deque*);
void freeDeque(Deque*);

Deque* newDeque(int cp){
    Deque *res = (Deque*)malloc(sizeof(Deque));
    res->a = (int*)malloc(cp*sizeof(int));
    res->cp = cp, res->front = res->rear = cp-1;
    return res;
}
void doubleSize(Deque *dq){
    int n = dq->cp*2, idx = dq->front;
    int *a = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < dq->cp-1; i++){
        idx = (idx+1)%dq->cp;
        a[i] = dq->a[idx];
    }
    free(dq->a);
    dq->a = a, dq->cp = n, dq->front = n-1, dq->rear = n/2-2;
}
bool full(Deque *dq){
    return (dq->rear+1)%dq->cp==dq->front;
}
bool empty(Deque *dq){
    return dq->front==dq->rear;
}
void pushBack(Deque *dq, int val){
    if(full(dq)) doubleSize(dq);
    dq->rear = (dq->rear+1)%dq->cp;
    dq->a[dq->rear] = val;
}
void pushFront(Deque *dq, int val){
    if(full(dq)) doubleSize(dq);
    dq->a[dq->front] = val;
    dq->front = (dq->front-1+dq->cp)%dq->cp;
}
void popBack(Deque *dq){
    dq->rear = (dq->rear-1+dq->cp)%dq->cp;
}
void popFront(Deque *dq){
    dq->front = (dq->front+1)%dq->cp;
}
int front(Deque *dq){
    return dq->a[(dq->front+1)%dq->cp];
}
int back(Deque *dq){
    return dq->a[dq->rear];
}
void freeDeque(Deque *dq){
    free(dq->a);
    free(dq);
}
