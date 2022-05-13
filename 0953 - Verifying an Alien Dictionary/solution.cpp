class Solution {
public:
    bool isAlienSorted(vector<string>& A, string order) {
        int m[26];
        for(int i = 0; i < 26; i++) m[order[i]-'a'] = i;
        auto cmp = [&](string& a, string& b){
            for(int i = 0; i < min(a.size(), b.size()); i++)
                if(a[i] != b[i]) return m[a[i]-'a'] < m[b[i]-'a'];
            return a.size() < b.size();
        };
        return is_sorted(A.begin(), A.end(), cmp);
    }
};