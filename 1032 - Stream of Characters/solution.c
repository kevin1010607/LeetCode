typedef struct _trie{
    bool end;
    struct _trie *next[26];
}Trie;
Trie *newTrie(){
    Trie *res = (Trie*)malloc(sizeof(Trie));
    res->end = false;
    for(int i = 0; i < 26; i++) res->next[i] = NULL;
    return res;
}
void insert(Trie **t, char *s){
    Trie *root = *t, *now = *t;
    int size = strlen(s);
    for(int i = size-1; i >= 0; i--){
        int id = s[i]-'a';
        if(!now->next[id]) now->next[id] = newTrie();
        now = now->next[id];
    }
    now->end = true;
    *t = root;
}
bool search(Trie *t, char *s, int size){
    Trie *now = t;
    for(int i = size-1; i >= 0; i--){
        int id = s[i]-'a';
        if(!now->next[id]) return false;
        if(now->next[id]->end) return true;
        now = now->next[id];
    }
    return false;
}
void freeTrie(Trie *t){
    if(!t) return;
    for(int i = 0; i < 26; i++) freeTrie(t->next[i]);
    free(t);
}
typedef struct{
    Trie *t;
    char *s;
    int idx;
}StreamChecker;
StreamChecker* streamCheckerCreate(char ** words, int wordsSize){
    StreamChecker *res = (StreamChecker*)malloc(sizeof(StreamChecker));
    res->t = newTrie();
    for(int i = 0; i < wordsSize; i++) insert(&(res->t), words[i]);
    res->s = (char*)calloc(400005, sizeof(char));
    res->idx = 0;
    return res;
}
bool streamCheckerQuery(StreamChecker* obj, char letter){
    obj->s[obj->idx++] = letter;
    return search(obj->t, obj->s, obj->idx);
}
void streamCheckerFree(StreamChecker* obj){
    freeTrie(obj->t);
    free(obj->s);
    free(obj);
}
/**
 * Your StreamChecker struct will be instantiated and called as such:
 * StreamChecker* obj = streamCheckerCreate(words, wordsSize);
 * bool param_1 = streamCheckerQuery(obj, letter);
 
 * streamCheckerFree(obj);
*/