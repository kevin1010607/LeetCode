typedef struct _d{
    bool isleaf;
    struct _d *next[26];
} WordDictionary;
WordDictionary* wordDictionaryCreate() {
    WordDictionary *res = (WordDictionary*)malloc(sizeof(WordDictionary));
    for(int i = 0; i < 26; i++) res->next[i] = NULL;
    res->isleaf = false;
    return res;
}
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    for(int i = 0; word[i]; i++){
        int idx = word[i]-'a';
        if(!obj->next[idx]) obj->next[idx] = wordDictionaryCreate();
        obj = obj->next[idx];
    }
    obj->isleaf = true;
}
bool search_rec(WordDictionary* obj, char *word, int now){
    if(!word[now]) return obj->isleaf;
    if(word[now] == '.'){
        for(int i = 0; i < 26; i++){
            if(obj->next[i] && search_rec(obj->next[i], word, now+1)) return true;
        }
    }
    else{
        int idx = word[now]-'a';
        if(obj->next[idx] && search_rec(obj->next[idx], word, now+1)) return true;
    }
    return false;
}
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    return search_rec(obj, word, 0);
}
void wordDictionaryFree(WordDictionary* obj) {
    for(int i = 0; i < 26; i++){
        if(obj->next[i]) wordDictionaryFree(obj->next[i]);
    }
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/