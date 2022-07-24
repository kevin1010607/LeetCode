bool searchMatrix(int** A, int ASz, int* AColSz, int target){
    int m = ASz, n = *AColSz, i = 0, j = n-1;
    while(i<m && j>=0){
        if(A[i][j] == target) return true;
        A[i][j]<target?i++:j--;
    }
    return false;
}