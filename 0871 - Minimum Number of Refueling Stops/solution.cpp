class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& A) {
        int res, i = 0, n = A.size();
        priority_queue<int> q;
        for(res = 0; fuel < target; res++){
            while(i<n && A[i][0]<=fuel)
                q.push(A[i++][1]);
            if(q.empty()) return -1;
            fuel += q.top(); q.pop();
        }
        return res;
    }
};