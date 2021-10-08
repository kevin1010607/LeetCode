class Trie{
private:
    bool leaf;
    Trie *next[26];
public:
    Trie(){
        leaf = false;
        for(int i = 0; i < 26; i++) next[i] = nullptr;
    }
    void insert(string word){
        Trie *now = this;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i]-'a';
            if(!now->next[idx]) now->next[idx] = new Trie();
            now = now->next[idx];
        }
        now->leaf = true;
    }
    bool search(string word){
        Trie *now = this;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i]-'a';
            if(!now->next[idx]) return false;
            now = now->next[idx];
        }
        return now->leaf;
    }
    bool startsWith(string prefix){
        Trie *now = this;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i]-'a';
            if(!now->next[idx]) return false;
            now = now->next[idx];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

