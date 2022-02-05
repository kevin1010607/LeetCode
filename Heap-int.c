// Heap method
#define SIZE 100
typedef struct{
    struct ListNode **heap;
    int num, capacity;
} Heap;
void swap(struct ListNode **l1, struct ListNode **l2){
    struct ListNode *tmp = *l1;
    *l1 = *l2;
    *l2 = tmp;
}
int cmp(struct ListNode *l1, struct ListNode *l2){
    return l1->val>l2->val;
}
Heap* heapCreate(){
    Heap *ret = (Heap*)malloc(sizeof(Heap));
    ret->heap = (struct ListNode**)malloc(SIZE*sizeof(struct ListNode*));
    ret->num = 0, ret->capacity = SIZE;
    return ret;
}
void doubleSize(Heap *obj){
    struct ListNode **h = (struct ListNode**)malloc((obj->capacity*2)*sizeof(struct ListNode*));
    for(int i = 0; i < obj->capacity; i++) h[i] = obj->heap[i];
    free(obj->heap);
    obj->heap = h, obj->capacity *= 2;
}
void heapInsert(Heap *obj, struct ListNode *l){
    if(obj->num == obj->capacity) doubleSize(obj);
    obj->heap[obj->num++] = l;
    int pos = obj->num-1, root = (pos-1)/2;
    while(pos!=0 && cmp(obj->heap[root], obj->heap[pos])){
        swap(&(obj->heap[root]), &(obj->heap[pos]));
        pos = root, root = (pos-1)/2;
    }
}
void heapDelete(Heap *obj){
    if(obj->num == 0) return;
    obj->heap[0] = obj->heap[obj->num-1];
    obj->num--;
    int pos = 0, childL = pos*2+1, childR = pos*2+2;
    while(childL < obj->num){
        int child = childL;
        if(childR<obj->num && cmp(obj->heap[childL], obj->heap[childR])) child = childR;
        if(cmp(obj->heap[child], obj->heap[pos])) break;
        swap(&(obj->heap[child]), &(obj->heap[pos]));
        pos = child, childL = pos*2+1, childR = pos*2+2;
    }
}
int heapGetNum(Heap *obj){
    return obj->num;
}
struct ListNode* heapTop(Heap *obj){
    return obj->heap[0]; 
}
void heapFree(Heap *obj){
    free(obj->heap);
    free(obj);
}