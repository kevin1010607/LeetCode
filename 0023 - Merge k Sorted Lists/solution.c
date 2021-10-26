/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Divide method
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *head = NULL;
    if(listsSize == 0) head = NULL;
    else if(listsSize == 1) head = lists[0];
    else if(listsSize == 2){
        if(!lists[0] || !lists[1]) head = !lists[0]?lists[1]:lists[0];
        else if(lists[0]->val < lists[1]->val){
            head = lists[0];
            lists[0] = lists[0]->next;
            head->next = mergeKLists(lists, 2);
        }
        else{
            head = lists[1];
            lists[1] = lists[1]->next;
            head->next = mergeKLists(lists, 2);
        }
    }
    else{
        int mid = listsSize/2;
        struct ListNode *s[2];
        s[0] = mergeKLists(lists, mid);
        s[1] = mergeKLists(lists+mid, listsSize-mid);
        head = mergeKLists(s, 2);
    }
    return head;
}

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
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *head = NULL, **now = &head;
    Heap *h = heapCreate();
    for(int i = 0; i < listsSize; i++) if(lists[i]) heapInsert(h, lists[i]);
    while(heapGetNum(h)){
        struct ListNode *node = heapTop(h);
        heapDelete(h);
        if(node->next) heapInsert(h, node->next);
        *now = node;
        now = &((*now)->next);
    }
    heapFree(h);
    return head;
}