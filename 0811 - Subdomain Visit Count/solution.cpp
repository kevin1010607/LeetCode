class Solution {
public:
    vector<string> subdomainVisits(vector<string>& A) {
        unordered_map<string, int> m;
        for(auto& s : A){
            int idx = s.find(' ');
            int times = stoi(s.substr(0, idx));
            for(int i = idx; i < s.size(); i++){
                if(s[i]!=' '&&s[i]!='.') continue;
                m[s.substr(i+1)] += times;
            }
        }
        vector<string> res;
        for(auto& [s, v] : m) res.emplace_back(to_string(v)+" "+s);
        return res;
    }
};