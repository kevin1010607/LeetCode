class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int m = A.size(), n = A[0].size(), i = 0, j = n-1;
        while(i<m && j>=0){
            if(A[i][j] == target) return true;
            A[i][j]<target?i++:j--;
        }
        return false;
    }
};