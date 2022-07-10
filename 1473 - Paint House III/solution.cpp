#define INF 0x3f3f3f3f
class Solution {
public:
    int minCost(vector<int>& A, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[2][101][21], minN[2][101][2], minIdx[2][101];
        memset(dp, 0x3f, sizeof(dp));
        memset(minN, 0x3f, sizeof(minN));
        memset(minIdx, 0x3f, sizeof(minIdx));
        auto cmp = [&](int j, int k){
            if(dp[1][j][k] < minN[1][j][0])
                minN[1][j][1] = minN[1][j][0], minN[1][j][0] = dp[1][j][k], minIdx[1][j] = k;
            else if(dp[1][j][k] < minN[1][j][1])
                minN[1][j][1] = dp[1][j][k];
        };
        for(int k = 1; k <= n; k++){
            if(A[0] == k) dp[1][1][k] = 0;
            else if(!A[0]) dp[1][1][k] = cost[0][k-1];
            cmp(1, k);
        }
        swap(dp[0], dp[1]);
        swap(minN[0], minN[1]);
        swap(minIdx[0], minIdx[1]);
        for(int i = 1; i < m; i++){
            for(int j = 1; j <= min(target, i+1); j++){
                for(int k = 1; k <= n; k++){
                    if(A[i] && A[i]!=k) continue;
                    dp[1][j][k] = min(minN[0][j-1][k==minIdx[0][j-1]], dp[0][j][k]);
                    if(!A[i]) dp[1][j][k] += cost[i][k-1];
                    cmp(j, k);
                }
            }
            swap(dp[0], dp[1]);
            swap(minN[0], minN[1]);
            swap(minIdx[0], minIdx[1]);
            memset(dp[1], 0x3f, sizeof(dp[1]));
            memset(minN[1], 0x3f, sizeof(minN[1]));
            memset(minIdx[1], 0x3f, sizeof(minIdx[1]));
        }
        return minN[0][target][0]<INF?minN[0][target][0]:-1;
    }
};