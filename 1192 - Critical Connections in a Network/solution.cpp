class Solution {
private:
    int dfs(int idx, int depth, vector<int>& rank, vector<vector<int>>& graph, vector<vector<int>>& res){
        rank[idx] = depth;
        int min_seen = depth;
        for(auto i: graph[idx]){
            if(rank[i] >= depth-1) continue;
            int seen = rank[i]==-2?dfs(i, depth+1, rank, graph, res):rank[i];
            if(seen > depth) res.push_back({idx, i});
            min_seen = min(min_seen, seen);
        }
        return min_seen;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& A) {
        vector<vector<int>> graph(n), res;
        vector<int> rank(n, -2);
        for(auto& i : A){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        dfs(0, 0, rank, graph, res);
        return res;
    }
};