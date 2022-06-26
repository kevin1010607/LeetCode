class Trie{
private:
    int w;
    vector<Trie*> next;
public:
    Trie(){
        next.resize(27);
    }
    ~Trie(){
        for(int i = 0; i < 27; i++)
            if(next[i]) delete next[i];
    }
    void add(string& s, int idx){
        Trie *now = this;
        for(auto c : s){
            int id = c-'a';
            if(!now->next[id]) now->next[id] = new Trie();
            now = now->next[id];
            now->w = idx;
        }
    }
    int search(string& s){
        Trie *now = this;
        for(auto c : s){
            int id = c-'a';
            if(!now->next[id]) return -1;
            now = now->next[id];
        }
        return now->w;
    }
};
class WordFilter {
private:
    Trie t;
public:
    WordFilter(vector<string>& A) {
        for(int i = 0; i < A.size(); i++){
            int n = A[i].size();
            for(int j = 1; j <= n; j++){
                string key = A[i].substr(n-j)+"{"+A[i];
                t.add(key, i);
            }
        }
    }
    
    int f(string pref, string suff) {
        string key = suff+"{"+pref;
        return t.search(key);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */