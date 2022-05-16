class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& A) {
        int n = A.size(), res = 1, d[] = {-1,-1,-1,0,1,1,1,0,-1,-1};
        if(A[0][0] || A[n-1][n-1]) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0}); A[0][0] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front(); q.pop();
                if(x==n-1 && y==n-1) return res;
                for(int i = 0; i < 8; i++){
                    int nx = x+d[i], ny = y+d[i+2];
                    if(nx<0||nx>=n||ny<0||ny>=n||A[nx][ny]) continue;
                    q.push({nx, ny}); A[nx][ny] = 1;
                }
            }
            res++;
        }
        return -1;
    }
};