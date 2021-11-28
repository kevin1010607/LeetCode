class Solution {
public:
    void dfs(vector<vector<int>>& graph, int n, vector<vector<int>>& res, int id, vector<int>& now){
        if(id == n-1){
            res.push_back(now);
            return;
        }
        for(auto i : graph[id]){
            now.push_back(i);
            dfs(graph, n, res, i, now);
            now.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> now(1, 0);
        dfs(graph, graph.size(), res, 0, now);
        return res;
    }
};