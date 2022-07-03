#define max(a,b) (((a)>(b))?(a):(b))
int wiggleMaxLength(int* A, int n){
    int up = 1, down = 1;
    for(int i = 1; i < n; i++){
        if(A[i] > A[i-1]) up = down+1;
        else if(A[i] < A[i-1]) down = up+1;
    }
    return max(up, down);
}