class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx1 = m-1, idx2 = n-1, idx = m+n-1;
        while(idx1>=0 && idx2>=0) A[idx--] = A[idx1]>B[idx2]?A[idx1--]:B[idx2--];
        while(idx2 >= 0) A[idx--] = B[idx2--];
    }
};