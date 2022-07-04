int candy(int* A, int n){
    int res = n, up = 0, down = 0, peak = 0;
    for(int i = 1; i < n; i++){
        if(A[i] > A[i-1]) 
            down = 0, peak = ++up, res += up;
        else if(A[i] < A[i-1]) 
            up = 0, ++down, res += down-(peak>=down);
        else 
            up = down = peak = 0;
    }
    return res;
}