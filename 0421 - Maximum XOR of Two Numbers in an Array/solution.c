#define max(a,b) (((a)>(b))?(a):(b))
typedef struct _trie{struct _trie *next[2];}Trie;
Trie *newTrie(){
    Trie *res = (Trie*)malloc(sizeof(Trie));
    res->next[0] = res->next[1] = NULL;
    return res;
}
void insert(Trie *t, int x){
    for(int i = 30; i >= 0; i--){
        int b = (x&(1<<i))>>i;
        if(!t->next[b]) t->next[b] = newTrie();
        t = t->next[b];
    }
}
int maxXor(Trie *t, int x){
    int res = 0;
    for(int i = 30; i >= 0; i--){
        int b = (x&(1<<i))>>i;
        if(t->next[!b]) res |= 1<<i, t = t->next[!b];
        else t = t->next[b];
    }
    return res;
}
void freeTrie(Trie *t){
    if(!t) return;
    freeTrie(t->next[0]);
    freeTrie(t->next[1]);
    free(t);
}
int findMaximumXOR(int* nums, int numsSize){
    int res = 0;
    Trie *t = newTrie();
    for(int i = 0; i < numsSize; i++) insert(t, nums[i]);
    for(int i = 0; i < numsSize; i++) res = max(res, maxXor(t, nums[i]));
    // freeTrie(t);
    return res;
}