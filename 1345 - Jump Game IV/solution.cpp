class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        queue<int> q; q.push(0);
        vector<int> v(n, INT_MAX); v[0] = 0;
        while(!q.empty()){
            int now = q.front(); q.pop();
            if(now == n-1) return v[now];
            if(now > 0) mp[arr[now]].push_back(now-1);
            if(now < n-1) mp[arr[now]].push_back(now+1);
            for(auto i : mp[arr[now]]){
                if(v[i] > v[now]+1){
                    v[i] = v[now]+1;
                    q.push(i);
                }
            }
            mp[arr[now]].clear();
        }
        return -1;
    }
};