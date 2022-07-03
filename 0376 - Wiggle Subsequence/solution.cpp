class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        int n = A.size(), up = 1, down = 1;
        for(int i = 1; i < n; i++){
            if(A[i] > A[i-1]) up = down+1;
            else if(A[i] < A[i-1]) down = up+1;
        }
        return max(up, down);
    }
};