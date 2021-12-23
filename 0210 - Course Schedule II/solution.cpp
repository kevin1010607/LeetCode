class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> in(n, 0), res;
        for(auto& i : prerequisites){
            graph[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int now = q.front(); q.pop();
            res.push_back(now);
            for(int i : graph[now]){
                if(--in[i] == 0) q.push(i);  
            }
        }
        return res.size()==n?res:vector<int>();
    }
};