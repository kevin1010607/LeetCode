#define P pair<int, int>
#define INF 0x3f3f3f3f
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& A, int n, int k) {
        int res = INT_MIN;
        vector<vector<P>> graph(n+1);
        vector<bool> seen(n+1);
        vector<int> dist(n+1, INF);
        for(auto& i : A) graph[i[0]].emplace_back(i[1], i[2]);
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, k}); dist[k] = 0;
        while(!q.empty()){
            auto [d, idx] = q.top(); q.pop();
            if(seen[idx]) continue;
            res = max(res, d), n--, seen[idx] = true;
            for(auto& [i, v] : graph[idx]){
                if(dist[idx]+v < dist[i]){
                    dist[i] = dist[idx]+v;
                    q.push({dist[i], i});
                }
            }
        }
        return n?-1:res;
    }
};