struct S{
    int v, i, j;
};
bool operator>(const S& a, const S& b){
    return a.v > b.v;
}
class Solution {
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int n = A.size();
        priority_queue<S, vector<S>, greater<S>> q;
        for(int j = 0; j < n; j++) 
            q.push({A[0][j], 0, j});
        for(int t = 0; t < k-1; t++){
            auto [v, i, j] = q.top(); q.pop();
            if(i != n-1) q.push({A[i+1][j], i+1, j});
        }
        return q.top().v;
    }
};