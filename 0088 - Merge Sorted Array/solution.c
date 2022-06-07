void merge(int* A, int ASz, int m, int* B, int BSz, int n){
    int idx1 = m-1, idx2 = n-1, idx = m+n-1;
    while(idx2 >= 0) A[idx--] = (idx1>=0 && A[idx1]>B[idx2])?A[idx1--]:B[idx2--];
}