class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> g(n);
        vector<int> degree(n, 0), res;
        for(auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            degree[e[0]]++, degree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(degree[i] == 1) q.push(i), degree[i]--;
        while(!q.empty()){
            int s = q.size();
            res.clear();
            while(s--){
                int now = q.front(); q.pop();
                res.push_back(now);
                for(auto i : g[now]){
                    degree[i]--;
                    if(degree[i] == 1) q.push(i);
                }
            }
        }
        return res;
    }
};