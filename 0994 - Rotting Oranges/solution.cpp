class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), time = 0, c = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) q.push(make_pair(i, j));
                else if(grid[i][j] == 1) c++;
            }
        }
        while(!q.empty()){
            int k = q.size(), p = 0;
            while(k--){
                int x = q.front().first, y = q.front().second, dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]!=1) continue;
                    grid[nx][ny] = 2, p = 1, c--;
                    q.push(make_pair(nx, ny));
                }
            }
            time += p;
        }
        return c?-1:time;
    }
};