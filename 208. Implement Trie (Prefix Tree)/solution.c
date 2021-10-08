typedef struct _trie{
    bool leaf;
    struct _trie *next[26];
}Trie;
Trie* trieCreate(){
    Trie *ret = (Trie*)malloc(sizeof(Trie));
    ret->leaf = false;
    for(int i = 0; i < 26; i++) ret->next[i] = NULL;
    return ret;
}
void trieInsert(Trie *obj, char *word){
    while(*word){
        int idx = *word-'a';
        if(!obj->next[idx]) obj->next[idx] = trieCreate();
        obj = obj->next[idx];
        word++;
    }
    obj->leaf = true;
}
bool trieSearch(Trie *obj, char *word){
   while(*word){
       int idx = *word-'a';
       if(!obj->next[idx]) return false;
       obj = obj->next[idx];
       word++;
   }
   return obj->leaf;
}
bool trieStartsWith(Trie *obj, char *prefix){
    while(*prefix){
        int idx = *prefix-'a';
        if(!obj->next[idx]) return false;
        obj = obj->next[idx];
        prefix++;
    }
    return true;
}
void trieFree(Trie *obj) {
    if(obj){
        for(int i = 0; i < 26; i++) trieFree(obj->next[i]);
        free(obj);
    } 
}
/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/

