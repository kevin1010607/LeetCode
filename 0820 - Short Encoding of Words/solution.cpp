class Trie{
private:
    bool isLeaf;
    vector<Trie*> next;
public:
    Trie(): isLeaf(true){
        next.resize(26);
    }
    ~Trie(){
        for(auto n : next) if(n) delete n;
    }
    void add(string& s){
        Trie *now = this;
        for(int i = s.size()-1; i >= 0; i--){
            int id = s[i]-'a';
            if(!now->next[id]) 
                now->next[id] = new Trie(), now->isLeaf = false;
            now = now->next[id];
        }
    }
    int dfs(int depth){
        if(isLeaf) return depth+1;
        int res = 0;
        for(auto n : next) 
            if(n) res += n->dfs(depth+1);
        return res;
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& A) {
        Trie t;
        for(auto& s : A) t.add(s);
        return t.dfs(0);
    }
};