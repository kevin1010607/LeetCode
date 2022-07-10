class Solution {
public:
    int minCostClimbingStairs(vector<int>& A) {
        int n = A.size();
        for(int i = 2; i < n; i++)
            A[i] += min(A[i-1], A[i-2]);
        return min(A[n-1], A[n-2]);
    }
};