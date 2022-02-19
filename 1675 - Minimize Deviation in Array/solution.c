void swap(int *a, int *b){
    int t = *a; *a = *b, *b = t;
}

typedef struct{
    int *a, size, cp;
}Heap;

Heap* newHeap(int);
void doubleSize(Heap*);
bool empty(Heap*);
bool full(Heap*);
int size(Heap*);
int top(Heap*);
void push(Heap*, int);
void pop(Heap*);
void freeHeap(Heap*);

Heap* newHeap(int cp){
    Heap *res = (Heap*)malloc(sizeof(Heap));
    res->a = (int*)malloc(cp*sizeof(int));
    res->size = 0, res->cp = cp;
    return res;
}
void doubleSize(Heap *h){
    h->cp *= 2;
    h->a = (int*)realloc(h->a, h->cp*sizeof(int));
}
bool empty(Heap *h){
    return h->size==0;
}
bool full(Heap *h){
    return h->size==h->cp;
}
int size(Heap *h){
    return h->size;
}
int top(Heap *h){
    return h->a[0];
}
void push(Heap *h, int val){
    if(full(h)) doubleSize(h);
    h->a[h->size++] = val;
    int pos = h->size-1, root = (pos-1)/2;
    while(pos && h->a[root]>h->a[pos]){
        swap(&h->a[root], &h->a[pos]);
        pos = root, root = (pos-1)/2;
    }
}
void pop(Heap *h){
    if(empty(h)) return;
    h->a[0] = h->a[--h->size];
    int pos = 0, L = pos*2+1, R = pos*2+2;
    while(L < h->size){
        int now = L;
        if(R<h->size && h->a[L]>h->a[R]) now = R;
        if(h->a[now] > h->a[pos]) break;
        swap(&h->a[now], &h->a[pos]);
        pos = now, L = pos*2+1, R = pos*2+2;
    }
}
void freeHeap(Heap *h){
    free(h->a);
    free(h);
}

int max(int a, int b) {return a>b?a:b;}
int min(int a, int b) {return a<b?a:b;}
int minimumDeviation(int* nums, int numsSize){
    int res = INT_MAX, mi = INT_MAX, n = numsSize;
    Heap *h = newHeap(105);
    for(int i = 0; i < n; i++){
        int now = nums[i]%2?nums[i]*2:nums[i];
        push(h, -now);
        mi = min(mi, now);
    }
    while(size(h) == n){
        int ma = -top(h); pop(h);
        res = min(res, ma-mi);
        if(ma%2 == 0) push(h, -ma/2), mi = min(mi, ma/2);
    }
    freeHeap(h);
    return res;
}