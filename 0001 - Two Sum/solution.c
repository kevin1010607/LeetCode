/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct _node{
    int key, val;
    struct _node *next;
}Node;
typedef struct{
    int size;
    Node **table;
}Map;
Node *newNode(int key, int val, Node *next){
    Node *res = (Node*)malloc(sizeof(Node));
    res->key = key, res->val = val, res->next = next;
    return res;
}
Map *newMap(int size){
    Map *res = (Map*)malloc(sizeof(Map));
    res->size = size;
    res->table = (Node**)calloc(size, sizeof(Node*));
    return res;
}
void mapInsert(Map *m, int key, int val){
    int h = abs(key)%m->size;
    m->table[h] = newNode(key, val, m->table[h]);
}
Node *mapFind(Map *m, int key){
    int h = abs(key)%m->size;
    Node *res = m->table[h];
    while(res){
        if(res->key == key) return res;
        res = res->next;
    }
    return NULL;
}
void mapFree(Map *m){
    for(int i = 0; i < m->size; i++){
        while(m->table[i]){
            Node *tmp = m->table[i];
            m->table[i] = tmp->next;
            free(tmp);
        }
    }
    free(m->table);
    free(m);
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Map *map = newMap(100);
    int *res = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++){
        Node *now = mapFind(map, nums[i]);
        if(now != NULL) {res[0] = i, res[1] = now->val; break;}
        else mapInsert(map, target-nums[i], i);
    }
    mapFree(map);
    return res;
}