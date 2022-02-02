/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {int *a, front, rear, cp;}Deque;
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
void push_back(Deque *dq, int val){
    if(full(dq)) doubleSize(dq);
    dq->rear = (dq->rear+1)%dq->cp;
    dq->a[dq->rear] = val;
}
void push_front(Deque *dq, int val){
    if(full(dq)) doubleSize(dq);
    dq->a[dq->front] = val;
    dq->front = (dq->front-1+dq->cp)%dq->cp;
}
void pop_back(Deque *dq){
    dq->rear = (dq->rear-1+dq->cp)%dq->cp;
}
void pop_front(Deque *dq){
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
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *res = (int*)malloc((numsSize-k+1)*sizeof(int));
    *returnSize = numsSize-k+1;
    Deque *dq = newDeque(k);
    for(int i = 0; i < numsSize; i++){
        if(!empty(dq) && front(dq) == i-k) pop_front(dq);
        while(!empty(dq) && nums[back(dq)]<nums[i]) pop_back(dq);
        push_back(dq, i);
        if(i >= k-1) res[i-(k-1)] = nums[front(dq)];
    }
    freeDeque(dq);
    return res;
}