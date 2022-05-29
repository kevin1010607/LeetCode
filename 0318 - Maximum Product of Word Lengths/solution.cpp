class Solution {
public:
    int maxProduct(vector<string>& A) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto& s : A){
            int key = accumulate(s.begin(), s.end(), 0, [](int res, char c){return res|(1<<(c-'a'));});
            for(auto& [i, v] : m)
                if(!(key & i)) res = max(res, (int)s.size()*v);
            m[key] = max(m[key], (int)s.size());
        }
        return res;
    }
};