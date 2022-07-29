class Solution {
private:
    string normal(string s){
        unordered_map<char, char> m;
        for(auto& c : s){
            if(!m.count(c)) m[c] = 'a'+m.size();
            c = m[c];
        }
        return s;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& A, string p) {
        vector<string> res;
        p = normal(p);
        for(auto& s: A)
            if(p == normal(s))
                res.push_back(s);
        return res;
    }
};