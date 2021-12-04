class Trie{
private:
    bool end;
    Trie *next[26];
public:
    Trie():end(false){
        for(int i = 0; i < 26; i++) next[i] = nullptr;
    }
    void insert(string& s){
        Trie *now = this;
        for(auto it = s.rbegin(); it != s.rend(); it++){
            int id = *it-'a';
            if(!now->next[id]) now->next[id] = new Trie();
            now = now->next[id];
        }
        now->end = true;
    }
    bool search(string& s){
        Trie *now = this;
        for(auto it = s.rbegin(); it != s.rend(); it++){
            int id = *it-'a';
            if(!now->next[id]) return false;
            if(now->next[id]->end) return true;
            now = now->next[id];
        }
        return false;
    }
};
class StreamChecker {
public:
    Trie t;
    string st;
    StreamChecker(vector<string>& words) {
        for(auto& s : words) t.insert(s);
    }
    bool query(char letter) {
        st += letter;
        return t.search(st);
    }
};
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */