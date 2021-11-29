class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    unordered_set<string> st;
    void dfs(string& str){
        res.back().push_back(str);
        st.insert(str);
        for(auto& s : m[str]){
            if(st.find(s) != st.end()) continue;
            dfs(s);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto& v : accounts){
            for(int i = 2; i < v.size(); i++){
                m[v[i]].push_back(v[i-1]);
                m[v[i-1]].push_back(v[i]);
            }
        }
        for(auto& v : accounts){
            if(st.find(v[1]) != st.end()) continue;
            res.push_back({v[0]});
            dfs(v[1]);
            sort(res.back().begin()+1, res.back().end());
        }
        return res;
    }
};
