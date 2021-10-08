 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SIZE 100
typedef struct _node{
    int key, val;
    struct _node *next;
}Node;
Node *newNode(int key, int val, Node* next){
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->key = key, ret->val = val, ret->next = next;
    return ret;
}
void insert(Node **map, int key, int val){
    int hash = abs(key)%SIZE;
    Node *n = newNode(key, val, map[hash]);
    map[hash] = n;
}
Node* find(Node **map, int key){
    int hash = abs(key)%SIZE;
    Node *now = map[hash];
    while(now){
        if(now->key == key) return now;
        now = now->next;
    }
    return NULL;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ret = (int*)malloc(sizeof(int)*2);
    Node* map[SIZE];
    for(int i = 0; i < SIZE; i++) map[i] == NULL;
    for(int i = 0; i < numsSize; i++){
        Node *f = find(map, target-nums[i]);
        if(f) {ret[0] = i, ret[1] = f->val; break;}
        else insert(map, nums[i], i);
    }
    return ret;
}
