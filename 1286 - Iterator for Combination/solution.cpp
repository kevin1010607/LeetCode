class CombinationIterator {
public:
    vector<string> v;
    int idx;
    void solve(string &s, int id, string now, int n){
        if(id == s.size()){
            if(now.size() == n) v.push_back(now);
            return;
        }
        string tmp = now;
        tmp += s[id];
        solve(s, id+1, now, n);
        solve(s, id+1, tmp, n);
    }
    CombinationIterator(string characters, int combinationLength) {
        solve(characters, 0, "", combinationLength);
        sort(v.begin(), v.end());
        idx = 0;
    }
    
    string next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx != v.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */